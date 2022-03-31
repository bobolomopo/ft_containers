/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:04:09 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 17:45:50 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "bst.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include <functional>
# include <memory>

namespace ft {
    template < class Key, class T,
    class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef typename ft::pair<const key_type, mapped_type>          value_type;
            typedef Compare                                                 key_compare;
            class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
				
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:
					bool operator() (const value_type& x, const value_type& y) const
					{ return (comp(x.first, y.first)); }
			};
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename ft::bst_it<value_type, Compare>                iterator;
            typedef typename ft::bst_it<const value_type, Compare>          const_iterator;
            typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t                                                  size_type;
        
		private:
            allocator_type          _alloc;
            key_compare             _comp;
            bst<value_type>    		_bst;
			size_type				_size;

        public:
        //Constructors && destructors && = operator
			explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _bst(), _comp(comp), _size(0) {};
			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type())
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _comp(comp), _alloc(alloc), _bst(), _size(0)
			{
				this->insert(first, last);
			};
			map (const map& x) : _alloc(x._alloc), _comp(x._comp), _bst(), _size(0)
			{
				this->insert(x.begin(), x.end());
			};
            ~map() { this->clear(); };
			map& operator= (const map& rhs)
			{
				if (&rhs == this)
					return (*this);
				this->clear();
				this->insert(rhs.begin(), rhs.end());
				return (*this);
			};
		//Iterators
		//Returns an iterator referring to the first element in the map container.
			iterator begin() { return (iterator(_bst.get_root(), _comp)._first); };
			const_iterator begin() const { return (const_iterator(_bst.get_root(), _comp)._first); };
		//Returns an iterator referring to the past-the-end element in the map container.
			iterator end() { return (iterator(_bst.get_root(), _comp)._last++); };
			const_iterator end() const { return (const_iterator(_bst.get_root(), _comp)._last++); };
		//Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
			reverse_iterator rbegin() { return (reverse_iterator(_bst.get_root(), _comp)._last); };
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(_bst.get_root(), _comp)._last); };
		//Returns a reverse iterator pointing to the theoretical element right before the first element in
		//the map container (which is considered its reverse end).
			reverse_iterator rend() { return (reverse_iterator(_bst.get_root(), _comp)._first++); };
			const_reverse_iterator rend() const { return (const_reverse_iterator(_bst, _comp)._first++); };
		//Capacity
		//Returns whether the map container is empty (i.e. whether its size is 0).
			bool empty() const { return (_size == 0); };
		//Returns the number of elements in the containers
			size_type size() const { return (_size); };
		//Returns the maximum number of elements that the map container can hold.
			size_type max_size() const { return (_alloc.max_size()); };
		//Element access
		//If k matches the key of an element in the container, the function returns a reference to its mapped value.
		//If k does not match the key of any element in the container, the function inserts a new element with that
		//key and returns a reference to its mapped value.
			mapped_type& operator[] (const key_type& k)
			{
				iterator tmp = this->find(k);

				if (tmp == this->end())
					this->insert(ft::make_pair(k, mapped_type()));
				tmp = this->find(k);
				return ((*tmp).second);
			};
		//Modifiers
		//insert functions
			pair<iterator,bool> insert (const value_type& val)
			{
				ft::pair<iterator, bool> ret;
				iterator tmp = this->find(val.first);

				if (tmp != this->end())
				{
					ret.second = 0;
					ret.first = tmp;
				}
				else
				{
					ret.second = 1;
					ret.first = this->insert(iterator(_bst.get_root()), val);
				}
				return (ret);
			};
			//give a hint of the position to insert the new value in the bst.
			//if its good begins from here, if not begins from the root of
			//the bst
			iterator insert (iterator position, const value_type& val)
			{
				iterator tmp = this->find(val.first);

				if (tmp != this->end())
					return (tmp);
				if (_size == 0)
				{
					_size++;
					return (this->_bst.insert(val));
				}
				_size++;
				return (this->_bst.insert(position, val));
			};
			//version with interators
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
				return ;
			};
			//erase iterators
			void erase (iterator position)
			{
				if (this->_bst.remove(position._node->_data))
					size--;
				return ;
			};
			size_type erase (const key_type& k)
			{
				iterator tmp = this->find(k);
				size_type ret = 0;

				if (tmp == this->end())
				{
					while (this->_bst.remove(ft::make_pair(k, mapped_type())))
					{
						_size--;
						ret++;
					}
				}
				return (ret);
			};
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					this->erase(first);
					first++;
				}
				return ;
			};
			//Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
			void swap (map& x)
			{
				ft::map<key_type, mapped_type> tmp = this;

				this = x;
				x = tmp;
				return ;
			};
			//delete all the elements from the map
			void clear() { this->erase(this->begin(), this->end()); };
			//Returns a copy of the comparison object used by the container to compare keys.
			key_compare key_comp() const { return (key_compare()); };
			//Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
			value_compare value_comp() const { return (value_compare(key_compare())); };
			//find the value search by the key of it
			iterator find (const key_type& k)
			{
				iterator tmp;

				tmp = this->_bst.search_by_key(ft::make_pair(k, mapped_type())));
				if (tmp)
					return (tmp);
				else
					return (this->end());
			};
			const_iterator find (const key_type& k) const
			{
				const_iterator tmp;

				tmp = this->_bst.search_by_key(ft::make_pair(k, mapped_type())));
				if (tmp)
					return (tmp);
				else
					return (this->end());
			};
			//counts the number of elements with the k key
			size_type count (const key_type& k) const
			{
				size_type ret = 0;
				iterator first = this->begin();
				iterator last = this->end();

				while (first != last)
				{
					if ((*first).first == k)
						return (ret++);
					first++;
				}
				return (ret);
			};
			//Returns an iterator pointing to the first element in the container whose key is not considered to go before k 
			iterator lower_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp((*beg).first, k) == false)
						break;
					beg++;
				}
				return (beg);
			}
			const_iterator lower_bound (const key_type& k) const { return (const_iterator(this->lower_bound(k))); };
			//Returns an iterator pointing to the first element in the container whose key is considered to go after k.
			iterator upper_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			};
			const_iterator upper_bound (const key_type& k) const { return (const_iterator(this->upper_bound(k))); };
			//Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const	
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			};
			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			};
			//return a copy of the allocator_type used by the map
			allocator_type get_allocator() const { return (this->_alloc); };
    };
}

#endif