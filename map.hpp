/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:04:09 by jandre            #+#    #+#             */
/*   Updated: 2022/03/30 01:07:29 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "binary_search_tree_iterator.hpp"
# include <functional>
# include <memory>

namespace ft {
    template < class Key,                                       // map::key_type
           class T,                                             // map::mapped_type
           class Compare = std::less<Key>,                      // map::key_compare
           class Alloc = std::allocator<pair<const Key,T> >     // map::allocator_type
           > class map;
}

#endif