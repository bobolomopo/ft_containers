/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_it.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:38:00 by jandre            #+#    #+#             */
/*   Updated: 2022/03/29 21:25:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP
# include "binary_search_tree_node.hpp"
# include "iterator_traits.hpp"

namespace ft {
    template <typename T, class Compare>
    class bst_it : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
			typedef typename T                                                                           value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer           pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference         reference;
        private:
            bst_node<value_type>      *_node;
            bst_node<value_type>      *_first;
            bst_node<value_type>      *_last;
            Compare                   _comp;
        public:
        //constructor and destructors
            bst_it(const Compare& comp = Compare()) : _node(NULL), _prev(NULL), _next(NULL), _comp(comp) {};
            bst_it(bst_node<value_type> *node, const Compare& comp = Compare()) : _node(node), _first(NULL), _last(NULL), _comp(comp)
            {
                bst_node<value_type>  *tmp = _node->_root;

                while (tmp->_left)
                    tmp = tmp->_left;
                _first = tmp;
                tmp = _node->_root;
                while (tmp->_right)
                    tmp = tmp->_right;
                _last = tmp;
            };
            bst_it(bst_it copy) : _node(copy._node), _first(copy._first), _last(copy._last), _comp(copy._comp) {};
            virtual ~bst_it() {};
        //operator overloads    
            bst_it &operator=(bst_it &rhs)
            {
                if (*this == rhs)
                    return (*this);
                this->_node = rhs._node;
                this->_first = rhs._first;
                this->_last = rhs._last;
                this->_comp = rhs._comp;
                return (*this);
            };
            bool operator==(value_type &rhs) { return (*this->_node == rhs); };
            bool operator!=(value_type &rhs) { return (*this->_node != rhs); };
        //reference && dereference
            value_type &operator*(void) const { return (*this->_node); };
            value_type *operator->(void) const {return (this->_node); };
        //increments and decrements
            bst_it& operator++(void)
            {
                bst_node<value_type> *tmp;
                if (_node == _last)
                    _node++;
                else if (_node->_right)
                {
                    tmp = _node->_right;
                    while (tmp->_left)
                        tmp = tmp->_left;
                    _node = tmp;
                }
                else
                {
                    tmp = _node->_parent;
                    while (_comp(tmp, _node->_parent))
                        tmp = tmp->_parent;
                    _node = tmp;
                }
                return (*this);
            };
            bst_it operator++(int)
            {
                bst_it tmp(*this);
                operator++();
                return (tmp);
            };
            bst_it& operator--(void)
            {
                bst_node<value_type> *tmp = _node;
                tmp--;
                if (_node == _first)
                    return (*this);
                else if (tmp == _last)
                {
                    _node = tmp;
                    return (*this);
                }
                else if (_node->_left)
                {
                    tmp = _node->_left;
                    while (tmp->_right)
                        tmp = tmp->_righ;
                    _node = tmp;
                }
                else
                {
                    tmp = _node->_parent;
                    while (!_comp(tmp, _node->_parent))
                        tmp = tmp->_parent;
                    _node = tmp;
                }
                return (*this);
            };
            bst_it operator--(int)
            {
                bst_it tmp(*this);
                operator--();
                return (tmp);
            };  
    };
}
#endif