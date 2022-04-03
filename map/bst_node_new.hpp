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

			value_type	_value;
			node		*_parent;
			node		*_left;
			node		*_right;

		//Constructor && destructors
			node () : _value(), _parent(NULL), _left(NULL), _right(NULL) {};
			node (node* parent = NULL, node *left = NULL, node *right = NULL) :
				_value(), _parent(parent), _left(left), _right(right)
			{};
			node (const value_type &val, node *parent = NULL, node *left = NULL, node *right = NULL) : 
				_value(val), _parent(parent), _left(left), _right(right)
			{};
			node (const node& copy) : _value(copy._value), _parent(copy._parent), _left(copy._left), _right(copy._right) {};
			virtual ~node() {}
			node &operator=(const node &rhs)
			{
				if (rhs == *this)
					return (*this);
				
				this->_value = rhs._value;
				this->_parent = rhs._parent;
				this->_left = rhs._left;
				this->_right = rhs._right;
				
				return (*this);
			}
			bool operator==(const node& rhs)
			{
				if (_value == rhs._value)
					return (true);
				return (false);
			}
	};
}

#endif