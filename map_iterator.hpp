/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:25:51 by jandre            #+#    #+#             */
/*   Updated: 2022/03/02 17:48:38 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{
    template <class K, class T>
	class MapIterator
	{
		public:
			typedef std::pair<K, T>	 value_type;
			typedef std::pair<K, T>& reference;
			typedef std::pair<K, T>* pointer;
		protected:
			pointer _ptr;
			pointer _right;
			pointer _left;
    };
}

#endif