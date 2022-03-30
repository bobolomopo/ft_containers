/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:48:31 by jandre            #+#    #+#             */
/*   Updated: 2022/03/30 22:58:25 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
    template <typename T>
    struct node
    {
        typedef T   value_type;
        
		node	*_root;
		node	*_parent;
        node	*_left;
        node	*_right;
        T		_data;

        node() : _root(NULL), _parent(NULL), _left(NULL), _right(NULL), _data() {};
        node(value_type new_data) : _root(NULL), _parent(NULL), _left(NULL), _right(NULL), _data(new_data) {};
        node(node const &copy) : _root(copy._root), _parent(copy._parent), _left(copy._left), _right(copy._right), _data(copy._data) {};
        node &operator=(node const &rhs)
        {
            if (*this == rhs)
                return (*this);
            this->_data = rhs._data;
            this->_left = rhs._left;
            this->_parent = rhs._parent;
            this->_right = rhs._right;
            this->_data = rhs._data;
            return (*this);
        };
        node &operator*(void) { return (this->_data); };
        node *operator->(void) { return (&this->_data); };
        bool operator==(const node &rhs) { return (this->_data == rhs._data); };
        bool operator>=(const node &rhs) { return (this->_data >= rhs._data); };
        bool operator<=(const node &rhs) { return (this->_data <= rhs._data); };
        bool operator>(const node &rhs) { return (this->_data > rhs._data); };
        bool operator<(const node &rhs) { return (this->_data < rhs._data); };
        bool operator!=(const node &rhs) { return (this->_data != rhs._data); };
    };
}