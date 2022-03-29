/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree_node.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:59:06 by jandre            #+#    #+#             */
/*   Updated: 2022/03/29 23:09:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_NODE_HPP
# define BINARY_SEARCH_TREE_NODE_HPP
# include "pair.hpp"
# include <cstddef>

namespace ft {
    template <class T>
    struct bst_node
    {
        public:
            typedef T        value_type;

        public:
            bst_node        *_root;
            bst_node        *_parent;
            bst_node        *_right;
            bst_node        *_left;
            value_type      _data;

        public:
            //Constructors && Destructors
            bst_node() : _parent(NULL), _right(NULL), _left(NULL), _data(), _root(this) {};
            bst_node(value_type data) : _parent(NULL), _right(NULL), _left(NULL), _data(data), _root(this) {};
            bst_node(value_type data, bst_node *root) : _parent(NULL), _right(NULL), _left(NULL), _data(data), _root(root){ this->add_node(root); };
            bst_node(bst_node &copy) : _root(copy._root), _right(copy._right), _left(copy._left), _parent(copy._parent), _data(copy._data) {};
            //operator overloads
            bst_node &operator= (const bst_node &rhs)
            {
                if (rhs == *this)
                    return (*this);
                this->_data = rhs._data;
                this->_parent = rhs._parent;
                this->_left = rhs._left;
                this->_right = rhs._right;
                this->_root = rhs._root;
                return (*this);
            };
            virtual ~bst_node() {};
            
            //overload operators
            bool operator==(const bst_node &other) const { return (this->_data == other._data); };
            bool operator>=(const bst_node &other) const { return (this->_data >= other._data); };
            bool operator<=(const bst_node &other) const { return (this->_data <= other._data); };
            bool operator<(const bst_node &other) const { return (this->_data < other._data); };
            bool operator>(const bst_node &other) const { return (this->_data > other._data); };
            bst_node operator*(void) const { return (this->_data); };

            //member functions
            void add_node(bst_node *parent)
            {
                this->_parent = parent;
                if (*this->_parent > *this)
                {
                    if (this->_parent->_left)
                        this->add_node(this->_parent->_left);
                    else
                        this->_parent->_left = this;
                    return ;
                }
                else if (*this->_parent < *this)
                {
                    if (this->_parent->_right)
                        this->add_node(this->_parent->_right);
                    else
                        this->_parent->_right = this;
                    return ;
                }
                return ;
            };
    };
}

#endif