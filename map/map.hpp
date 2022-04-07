/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:27:45 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 11:04:45 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "tree.hpp"
# include "../utils/pair.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft {
    template < class Key,
			   class T,
			   class Compare = std::less<Key>,
			   class Alloc = std::allocator<ft::pair<const Key, T> >
			   >
	class map
	{
        public:
            typedef Key												key_type;
            typedef T												mapped_type;
            typedef ft::pair<const key_type, mapped_type>			value_type;
            typedef Compare											key_compare;
            typedef Alloc											allocator_type;
            typedef typename allocator_type::reference				reference;
            typedef typename allocator_type::const_reference		const_reference;
            typedef typename allocator_type::pointer				pointer;
            typedef typename allocator_type::const_pointer			const_pointer;
            typedef typename allocator_type::difference_type		difference_type;
            typedef typename allocator_type::size_type				size_type;

        private:
            typedef Node<value_type>								node_type;
            typedef node_type *										node_pointer;
            typedef tree<value_type, key_compare, allocator_type>	tree_type;

        public:
            typedef typename tree_type::iterator					iterator;
            typedef typename tree_type::const_iterator				const_iterator;
            typedef typename tree_type::reverse_iterator			reverse_iterator;
            typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;

            class value_compare
            {
                friend class map;

            protected:
                Compare	comp;
                value_compare(Compare c) : comp(c) {}

            public:
                typedef bool		result_type;
                typedef value_type	first_argument_type;
                typedef value_type	second_argument_type;
                bool	operator()(const value_type& x, const value_type& y) const {
                    return comp(x.first, y.first);
                };
            };

        private:
            tree_type			_tree;
            key_compare			_comp;
		
		public:
		//Constructors && Destructors
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc), _comp(comp) {};
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _tree(comp, alloc), _comp(comp) 					{ this->insert(first, last); };
		map(const map& x) : _comp(x._comp)						{ this->insert(x.begin(), x.end()); };
		~map() 													{ this->clear(); };

		map &operator=(const map &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->clear();
			this->insert(rhs.begin(), rhs.end());
			return (*this);
		};

		//Iterators
		iterator begin()										{ return (this->_tree.begin()); };
		const_iterator begin() const							{ return (this->_tree.begin()); };
		iterator end()											{ return (this->_tree.end()); };
		const_iterator end() const								{ return (this->_tree.end()); };
		reverse_iterator rbegin()								{ return (this->_tree.rbegin()); };
		const_reverse_iterator rbegin() const					{ return (this->_tree.rbegin()); };
		reverse_iterator rend()									{ return (this->_tree.rend()); };
		const_reverse_iterator rend() const						{ return (this->_tree.rend()); };
    
		//Capacity and size
		bool empty() const										{ return (this->_tree.empty()); };
		size_type size() const									{ return (this->_tree.size()); };
		size_type max_size() const								{ return (this->_tree.max_size()); };
	
		//Element access
		//If the key doesnt not exist, create one with no elements mapped_type in it.
		mapped_type	&operator[](const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		};

		//insert a new node containing value val in the tree
		pair<iterator, bool> insert(const value_type& val) 
		{
			if (this->count(val.first)) //if the element already in the map, return false and a pointer to the pair
				return ft::make_pair(this->find(val.first), false);
			this->_tree.insert(val);
			return ft::make_pair(this->find(val.first), true);
		};
		//insert a new node containing value val in the tree, try to hint the position of the new node
		iterator insert(iterator position, const value_type &val)
		{
			node_pointer temp = position.base();
			node_pointer successor = get_successor(temp);
			node_pointer end = this->_tree.get_end();

			if ((temp != end && temp->data.first < val.first) &&
				(successor == end || successor->data.first > val.first)) //checking if the position is good to insert
				position = iterator(this->_tree.insert_hint(temp, val));
			else
				position = this->insert(val).first;
			return (position);
		};
		//insert the range of value pointed by first to value pointed by last
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			while (first != last)
				this->insert((*first++));
		};

		//erase the node at position
		void erase(iterator position) 							{ this->erase((*position).first); };
		//if a node with key k is found, erase it, return number of node erased (1 or 0)
		size_type erase(const key_type &k)
		{
			size_type temp_size = this->size();
			
			this->_tree.delete_node(k);
			if (this->size() != temp_size)
				return (1);
			return (0);
		};
		//erase all the node in the range first to last
		void erase(iterator first, iterator last)
		{
			iterator temp;
			
			while (first != last)
			{
				temp = first;
				first++;
				this->erase((*temp).first);
			}
		};

		//Swap the value of two maps (size may change)
		void swap(map &x)										{ this->_tree.swap(x._tree); };
		//erase all the content of the map
		void clear()											{ this->_tree.clear(); };

		//returns the Compare paramater (by default it is std::less for a map)
		key_compare key_comp() const							{ return (key_compare()); };
		value_compare value_comp() const						{ return (value_compare(this->_comp)); };

		//returns an iterator to the node with key value k, end if not found
		iterator find(const key_type& k)						{ return (iterator(this->_tree.find(k))); };
		const_iterator find(const key_type& k) const			{ return (const_iterator(this->_tree.find(k))); };
		
		//count number of time k type is found in the map (in normals map its 1 or 0)
		size_type count(const key_type& k) const				{ return (_tree.is_found(k)); };
		
		//Returns an iterator pointing to the first element in the container whose key is not considered to go before k
		iterator lower_bound(const key_type& k)					{ return (iterator(this->_tree.lower_bound(k))); };
		const_iterator lower_bound(const key_type &k) const		{ return (const_iterator(this->_tree.lower_bound(k))); };
		
		//Returns an iterator pointing to the first element in the container whose key is considered to go after k
		iterator upper_bound(const key_type &k)					{ return (iterator(this->_tree.upper_bound(k))); };
		const_iterator upper_bound(const key_type &k) const		{ return (const_iterator(this->_tree.upper_bound(k))); };
		
		//Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
		pair<iterator, iterator> equal_range(const key_type &k)	{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); };
		pair<const_iterator, const_iterator> equal_range
			(const key_type &k) const							{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); };
	
		//Returns a copy of the allocator object associated with the map
		allocator_type get_allocator() const 					{ return allocator_type(this->_tree.get_allocator()); };
	};

	template< class Key, class T, class Compare, class Alloc >
	void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) { x.swap(y); };

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && ft::equal(rhs.begin(), rhs.end(), lhs.begin()));
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(operator==(lhs, rhs)));
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		bool equal = operator==(lhs, rhs);
		if (equal)
			return (equal);
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		bool equal = operator==(lhs, rhs);
		if (equal)
			return (equal);
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
}

#endif