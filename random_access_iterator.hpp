/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:32:20 by jandre            #+#    #+#             */
/*   Updated: 2022/03/21 23:11:06 by jandre           ###   ########.fr       */
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
            random_access_iterator(random_access_iterator &rhs) : _ptr(rhs._ptr) {};
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
            pointer operator->(void) { return &(this->operator*()); };
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
            random_access_iterator operator+(difference_type n) const { return (_ptr + n); };
            random_access_iterator operator-(difference_type n) const { return (_ptr - n); };
            random_access_iterator& operator+=(difference_type n)
            {
                _ptr += n;
                return (*this);
            };
            random_access_iterator& operator-=(difference_type n)
            {
                _ptr -= n;
                return (*this);
            };
            reference operator[](difference_type n) { return (*(operator+(n))); };
            operator random_access_iterator<const T> () const
            { return (random_access_iterator<const T>(this->_ptr)); };
            //accessors
            pointer base() const { return (this->_ptr); };
        private:
            pointer _ptr;
    };
    //All boolean operations
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator==(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    };
    //operation with the iterator
    template<typename T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        typename ft::random_access_iterator<T>& rai)
    {
        return (&(*rai) + n);
    };
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    };
}

#endif