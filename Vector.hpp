/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:47:09 by jandre            #+#    #+#             */
/*   Updated: 2022/02/28 19:33:19 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "VectorIterators.hpp"
# include <memory>


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
            reference operator[](size_type n)
			{
				return (this->_container[n]);
			};
			const_reference operator[](size_type n) const
			{
				return (this->_container[n]);
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
            
    };
};

#endif