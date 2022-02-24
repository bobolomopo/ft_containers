/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:47:09 by jandre            #+#    #+#             */
/*   Updated: 2022/02/24 14:23:41 by jandre           ###   ########.fr       */
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
            //all typedef to have the same variable name than cpluscplus.com
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
            explicit Vector(const allocator_type &allocator = allocator_type())
            : _length(0), _size(0), _container(0), _allocator(allocator)
            {
                this->_container = _allocator.allocate(0);
                return ;
            };

    };
};

#endif