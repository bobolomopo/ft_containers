/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:32:28 by jandre            #+#    #+#             */
/*   Updated: 2022/03/22 22:34:24 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {
    template <class Iterator>
    class reverse_iterator {
         public:
         //All typedef for the reverse iterator
            typedef Iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category    iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type           value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type      difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer              pointer;
            typedef typename ft::iterator_traits<Iterator>::reference            reference;
            reverse_iterator()
            :
                _ptr()
            {};
            explicit reverse_iterator (iterator_type it)
            :
                _ptr(it.base())
            {};
            template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                :
                    _ptr(rev_it->_ptr)
            {};
            virtual ~reverse_iterator() {};
        //operator overloads
        //dereference et reference
            reference operator*() const
            {
                iterator_type tmp = _ptr;
                return (*(--tmp));
            };
            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_ptr - n)); };
        //increments and decrements
            reverse_iterator& operator++()
            {
                --_ptr;
                return (*this);
            };
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            };
        //normal operations
            reverse_iterator& operator+= (difference_type n)
            {
                _ptr -= n;
                return (*this);
            };
            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_ptr + n)); };
            reverse_iterator& operator--()
            {
                ++_ptr;
                return (*this);
            };
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            };
            reverse_iterator& operator-= (difference_type n)
            {
                _ptr += n;
                return (*this);
            };
            pointer operator->() const { return &(operator*()); };
            reference operator[] (difference_type n) const { return (this->_ptr[n]); };
        //boolean operator
            bool operator==(const reverse_iterator &other) const
            {
                return (_ptr == other._ptr);
            };
            bool operator!=(const reverse_iterator &other) const
            {
                return (_ptr != other._ptr);
            };
            bool operator>(const reverse_iterator &other) const
            {
                return (_ptr > other._ptr);
            };
            bool operator>=(const reverse_iterator &other) const
            {
                return (_ptr >= other._ptr);
            };
            bool operator<(const reverse_iterator &other) const
            {
                return (_ptr < other._ptr);
            };
            bool operator<=(const reverse_iterator &other) const
            {
                return (_ptr <= other._ptr);
            };

        private:
            pointer     _ptr;
    };
}


#endif