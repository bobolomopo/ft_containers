/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarhsre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:21:20 by jarhsre            #+#    #+#             */
/*   Updated: 2022/04/03 16:21:38 by jarhsre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft {
	template <typename T>
	struct node
	{
		public :
			typedef T	value_type;

			value_type	_data;
			node		*_parent;
			node		*_left;
			node		*_right;

		//Constructor && destructors
			node () : _data(), _parent(NULL), _left(NULL), _right(NULL) {};
			node (node* parent = NULL, node *left = NULL, node *right = NULL) :
				_data(), _parent(parent), _left(left), _right(right)
			{};
			node (const value_type &val, node *parent = NULL, node *left = NULL, node *right = NULL) : 
				_data(val), _parent(parent), _left(left), _right(right)
			{};
			node (const node& copy) : _data(copy._data), _parent(copy._parent), _left(copy._left), _right(copy._right) {};
			virtual ~node() {}
			node &operator=(const node &rhs)
			{
				if (rhs == *this)
					return (*this);
				
				this->_data = rhs._data;
				this->_parent = rhs._parent;
				this->_left = rhs._left;
				this->_right = rhs._right;
				
				return (*this);
			}
			bool operator==(const node& rhs)
			{
				if (_data == rhs._data)
					return (true);
				return (false);
			}
	};
}

#endif