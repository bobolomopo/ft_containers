/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:32:20 by jandre            #+#    #+#             */
/*   Updated: 2022/03/22 22:34:12 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {
    //Random-access iterators are iterators that can be used to access elements 
    //at an arbitrary offset position relative to the element they point to, offering the same functionality as pointers.
    //it is the type of iterators used by vectors containers.
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
        public:
        //All the typedef of the iterator
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
            typedef T*               pointer;
            typedef T&             reference;
        public:
        //Constructors
            random_access_iterator(void) : _ptr(NULL) {};
            random_access_iterator(pointer ptr) : _ptr(ptr) {};
            random_access_iterator(const random_access_iterator &rhs) : _ptr(rhs._ptr) {};
            virtual ~random_access_iterator(void) {};
        //operator overloads
            random_access_iterator &operator=(const random_access_iterator& rhs)
            {
                if (this == &rhs)
                    return (*this);
                this->_ptr = rhs._ptr;
                return (*this);
            };
        //reference and dereference
            reference operator*(void) const { return (*_ptr); };
            pointer operator->(void) { return (this->_ptr); };
        //accessor
            pointer base()
            {
                return (this->_ptr);
            }
        //incrementation and decrementation    
            random_access_iterator& operator++(void)
            {
                _ptr++;
                return (*this);
            };
            random_access_iterator operator++(int)
            {
                random_access_iterator tmp(*this);
                operator++();
                return (tmp);
            };
            random_access_iterator& operator--(void)
            {
                _ptr--;
                return (*this);
            };
            random_access_iterator operator--(int)
            {
                random_access_iterator tmp(*this);
                operator--();
                return (tmp);
            };
            random_access_iterator operator+(difference_type n)
            {
                random_access_iterator tmp(this->_ptr + n);
                return (tmp);
            };
            random_access_iterator operator-(difference_type n)
            {
                random_access_iterator tmp(this->_ptr - n);
                return (tmp);
            };
            random_access_iterator& operator+=(difference_type n)
            {
                this->_ptr += n;
                return (*this);
            };
            random_access_iterator& operator-=(difference_type n)
            {
                this->_ptr -= n;
                return (*this);
            };
            reference operator[](difference_type n) { return (*(operator+(n))); };
            operator random_access_iterator<const T> () const
            { return (random_access_iterator<const T>(this->_ptr)); };
            //boolean operators
            bool operator==(const random_access_iterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const random_access_iterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const random_access_iterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const random_access_iterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const random_access_iterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const random_access_iterator &other) const
			{
				return (_ptr <= other._ptr);
			};
        private:
            pointer _ptr;
    };
}

#endif