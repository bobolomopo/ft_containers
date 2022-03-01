/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:47:09 by jandre            #+#    #+#             */
/*   Updated: 2022/03/01 18:40:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "VectorIterators.hpp"
# include <memory>
# include <stdexcept>


namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
        // all typedef to have the same variable name than cpluscplus.com
            typedef T                                   value_type;
            typedef Alloc                               allocator_type;
            typedef T&                                  reference;
            typedef const T&                            const_reference;
            typedef T*                                  pointer;
            typedef const T*                            const_pointer;
            typedef ft::VectorIterator<T>               iterator;
            typedef ft::ConstVectorIterator<T>          const_iterator;
            typedef ft::ReverseVectorIterator<T>        reverse_iterator;
            typedef ft::ConstReverseVectorIterator<T>   const_reverse_iterator;
            typedef unsigned int                        size_type;
        
        private:
            size_type       _length;
            size_type       _size;
            pointer         _container;
            allocator_type  _allocator;

        public:
        // Constructor && destructor
        // empty container constructor (default constructor) : Constructs an empty container, with no elements
            explicit Vector(const allocator_type &allocator = allocator_type())
            : _length(0), _size(0), _container(0), _allocator(allocator)
            {
                this->_container = this->_allocator.allocate(0);
                return ;
            };
        // fill constructor : Constructs a container with n elements. Each element is a copy of val.
            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) :
                 _length(0),  _size(0), container(NULL), _allocator(allocator)
            {
                this->_container = this->_allocator.allocate(0);
                this->assign(n, value);
                return ;
            };
        // range constructor
        // Constructs a container with as many elements as the range [first,last), 
        // with each element constructed from its corresponding element in that range, in the same order.
            template <class InputIterator>
			Vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
			: _length(0), r_size(0), _container(NULL), _allocator(allocator)
			{
				this->_container = this->_allocator.allocate(0);
				this->assign(begin, end);
                return ;
			};
        // copy constructor
        // Constructs a container with a copy of each of the elements in rhs, in the same order.
            Vector(const Vector &rhs)
			: _length(0), _size(0), _container(NULL), _allocator(rhs._allocator)
			{
				*this = rhs;
                return ;
			};
        // Destructor
            ~Vector(void)
			{
				this->_allocator.deallocate(this->_container, this->_size);
                return ;
			};
        
        // Operator overloads
            Vector &operator=(const Vector &other)
			{
				if (this->_container != 0)
					this->_allocator.deallocate(this->_container, this->_size);
				this->_allocator = other._allocator;
				this->_size = 0;
				this->_length = 0;
				this->_container = this->_allocator.allocate(0);
				this->assign(other.begin(), other.end());
				return (*this);
			};
    
        // Iterators
        // Returns an iterator pointing to the first element in the vector.
            iterator begin(void)
			{
				return (iterator(this->_container));
			};
        // Returns an iterator referring to the past-the-end element in the vector container.
			iterator end(void)
			{
				return (iterator(this->_container + this->_length));
			};
        // Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(this->_container + this->_length - 1));
			};
        // Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
			reverse_iterator rend(void)
			{
				return (reverse_iterator(this->_container - 1));
			};
        // Returns a constant iterator pointing to the first element in the vector.
        	const_iterator begin(void) const
			{
				return (const_iterator(this->_container));
			};
        // Returns a constant iterator referring to the past-the-end element in the vector container.
            const_iterator end(void) const
			{
				return (const_iterator(this->_container + this->_length));
			};
        // Returns a constant reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
            const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(this->_container + this->_length - 1));
			};
        // Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(this->_container - 1));
			};
    
        // Member functions
        // Returns the number of elements in the vector.
            size_type size() const
            {
                return (this->length);
            };
        // Returns the maximum number of elements that the vector can hold..
            size_type max_size(void) const
            {
                return (std::numeric_limits<size_type>::max() / sizeof(value_type));
            };
        // Resizes the container so that it contains n elements.
            void resize(size_type n, value_type value = value_type())
			{
				while (n < this->_length)
					this->pop_back();
				while (n > this->_length)
					this->push_back(value);
			};
        // Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
            size_type capacity(void) const
			{
				return (this->_size);
			};
        // Returns whether the vector is empty (i.e. whether its size is 0).
            bool empty(void) const
			{
				return (this->_length == 0);
			};
        // Requests that the vector capacity be at least enough to contain n elements.
            void reserve(size_type n)
			{
                if (n > this->max_size())
                    throw(std::length_error());
				if (n > this->_size)
				{
					size_type i = -1;
					pointer	tmp;
					tmp  = this->_allocator.allocate(n);
					this->_size = n;
					while (++i < this->_length)
						tmp[i] = this->_container[i];
					this->_allocator.deallocate(this->_container, this->_size);
					this->_container = tmp;
				}
			};
        // Element access
        // Returns a reference to the element at position n in the vector container.
            reference operator[](size_type n)
			{
				return (this->_container[n]);
			};
        // Returns a constant reference to the element at position n in the vector container.
			const_reference operator[](size_type n) const
			{
				return (this->_container[n]);
			};
        // Returns a reference to the element at position n in the vector. throws out_of_range exeption if out of range
            reference at(size_type n)
			{
				if (n >= _container_length || n < 0)
					throw (std::out_of_range());
				return (this->_container[n]);
			};
        // Returns a constant reference to the element at position n in the vector. throws out_of_range exeption if out of range
			const_reference at(size_type n) const
			{
				if (n >= _container_length || n < 0)
					throw (std::out_of_range());
				return (this->_container[n]);
			};
        // Returns a reference to the first element in the vector.
            reference front(void)
			{
				return (this->_container[0]);
			};
        // Returns a constant reference to the first element in the vector.
			const_reference front(void) const
			{
				return (this->_container[0]);
			};
        // Returns a reference to the last element in the vector.
            reference back(void)
			{
				return (this->_container[this->_length - 1]);
			};
        // Returns a constant reference to the last element in the vector.
			const_reference back(void) const
			{
				return (this->_container[this->_length - 1]);
			};
        // Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
        // Range : The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last)
			{
				this->clear();
				this->insert(this->begin(), first, last);
			};
        // Fill : The new contents are n elements, each initialized to a copy of val.
			void assign(size_type n, const value_type &value)
			{
				this->clear();
				this->insert(this->begin(), n, value);
			};
        // Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
            void push_back(const value_type &value)
			{
				if (this->_length + 1 > this->_size)
					this->reserve(this->_length + 1);
				this->_container[this->_length++] = value;
			};
        // Removes the last element in the vector, effectively reducing the container size by one.
            void pop_back(void)
			{
				if (this->_length)
					this->_length--;
			};
        // The vector is extended by inserting new elements before the element at the specified position, 
        // effectively increasing the container size by the number of elements inserted.
        // Single element
            iterator insert(iterator position, const value_type &value)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < this->_length)
					i++;
				if (this->_size < this->_length + 1)
					reserve(this->_length + 1);
				size_type j = this->_size - 1;
				while (j > i)
				{
					this->_container[j] = this->_container[j - 1];
					j--;
				}
				this->_container[i] = value;
				this->_length++;
				return (iterator(&this->_container[i]));
			};
        // Fill version
            void insert(iterator position, size_type n, const value_type &value)
			{
				while (n--)
					position = this->insert(position, value);
			};
        // Range version
			template <class InputIterator>
			void insert(iterator position, InputIterator begin, InputIterator end)
			{
				while (begin != end)
				{
					position = this->insert(position, *begin) + 1;
					++begin;
				}
			};
        // Removes from the vector either a single element (position) or a range of elements ([first,last)).
        // Single element
            iterator erase(iterator position)
			{
				iterator cursor = position;
				while (cursor + 1 != end())
				{
					*cursor = *(cursor + 1);
					cursor++;
				}
				this->_length--;
				return (iterator(position));
			};
        // Range of elements
			iterator erase(iterator begin, iterator end)
			{
				while (begin != end)
				{
					erase(begin);
					end--;
				}
				return (iterator(begin));
			};
        // Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
            void swap (vector& x)
            {
                vector<value_type> tmp(this);

                this = x;
                x = tmp;
            };
        // Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
            void clear(void)
			{
				this->erase(this->begin(), this->end());
			};
        // Returns a copy of the allocator object associated with the vector.
            allocator_type get_allocator() const
            {
                return (this->_allocator);
            };
    };
// Non member fonction
// Boolean operator
    template<class T, class Alloc>
    bool operator==(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template<class T, class Alloc>
	bool operator!=(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		return (!(a == b));
	};
	template <class T, class Alloc>
	bool operator<(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		size_t		i;
		size_t		n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = 0;
		while (i < n)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
			i++;
		}
		return (a.size() < b.size());
	}
	template <class T, class Alloc>
	bool operator<=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (a < b || a == b);
	}

	template <class T, class Alloc>
	bool operator>(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}
	template <class T, class Alloc>
	bool operator>=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b));
	}
// Non member fonction swap
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    };
};

#endif