/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:28:31 by jandre            #+#    #+#             */
/*   Updated: 2022/04/01 22:16:40 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <cstddef>
# include <typeinfo>
# include <stdexcept>

namespace ft {
    //prototypes of the two types of iterators needed for the category of the iterator traits of map and vector.
    class bidirectional_iterator_tag {};
    class random_access_iterator_tag {};
    
    //Identificator of iterator needed for the containers
    template <bool is_valid, typename T>
        struct valid_iterator_tag_base { typedef T type; const static bool value = is_valid; };
    //Case if its not tagged set the bool to false
    template <typename T>
        struct is_iterator_tagged : public valid_iterator_tag_base<false, T> { };
    //Check is_input_iterator_tagged from ft::random_access_iterator_tag
    template <>
        struct is_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_base<true, ft::random_access_iterator_tag> { };
    //Check is_input_iterator_tagged from ft::bidirectional_iterator_tag
    template <>
        struct is_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_base<true, ft::bidirectional_iterator_tag> { };
    
    template <typename T>
    class invalid_iterator_exception : public std::exception
    {
        private:
            std::string _msg;
        
        public :
            invalid_iterator_exception () throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
            invalid_iterator_exception (const invalid_iterator_exception&) throw() {}
            invalid_iterator_exception& operator= (const invalid_iterator_exception&) throw() {}
            virtual ~invalid_iterator_exception() throw() {}
            virtual const char* what() const throw() { return (_msg.c_str()); }
    };

    //Generic definition of iterator traits
    template <class Iterator> class iterator_traits
    {
        public:
        //All the typedef for iterator_traits
            typedef typename Iterator::difference_type       difference_type;
            typedef typename Iterator::value_type            value_type;
            typedef typename Iterator::pointer               pointer;
            typedef typename Iterator::reference             reference;
            typedef typename Iterator::iterator_category     iterator_category;
    };
    template <class T> class iterator_traits<T*>
    {
        public:
        //All typedef for T* specialization
        //ptrdiff_t is a type for difference of adresses.
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef ft::random_access_iterator_tag  iterator_category;
    };
    template <class T> class iterator_traits<const T*>
    {
        public:
        //All typedef for const T* specialization
        //ptrdiff_t is a type for difference of adresses.
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef ft::random_access_iterator_tag  iterator_category;
    };

    //This is a base class template that can be used to derive iterator
    //classes from it. It is not an iterator class and does not provide any of the 
    //functionality an iterator is expected to have.
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&> 
    class iterator
    {
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
    };
}

#endif