/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:59:14 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 16:23:26 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "../utils/iterator_traits.hpp"

namespace ft {
    template <class Node_Type, class T>
	class tree_it : public ft::iterator<ft::bidirectional_iterator_tag, T> 
	{
		public:
			typedef T																						value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category 			iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type				difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type					value_type_traits;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference						reference_traits;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer						pointer_traits;
			typedef Node_Type	*																			node_pointer;
			typedef value_type	&																			reference;
			typedef value_type	*																			pointer;
		private:
			node_pointer _node;
		
		public:
			tree_it() : _node() {};
			tree_it(node_pointer node) : _node(node) {};
			template<typename U>
			tree_it(const tree_it<Node_Type, U> &copy) : _node(copy.base()) {};
			tree_it &operator=(const tree_it &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			};
			virtual ~tree_it() {};

			operator tree_it<const Node_Type, T>(void) const { return tree_it<const Node_Type, T>(this->_node); }
			node_pointer base() const		{ return (this->_node); };
			reference operator*() const		{ return (this->_node->data); };
			pointer operator->() const		{ return (&(operator*())); };
			tree_it& operator++()			{ this->_node = get_successor(this->_node); return (*this); };
			tree_it operator++(int)			{ tree_it temp(*this); ++(*this); return (temp); };
			tree_it& operator--()			{ this->_node = get_predecessor(this->_node); return (*this); };
			tree_it operator--(int)			{ tree_it temp(*this); --(*this); return (temp); };
	};

	template <typename Node_Type, typename T, class U>
	bool	operator==(const tree_it<Node_Type, T>& lhs, const tree_it<Node_Type, U>& rhs)
	{ return (lhs.base() == rhs.base()); };
	
	template <typename Node_Type, typename T, class U>
	bool	operator!=(const tree_it<Node_Type, T>& lhs, const tree_it<Node_Type, U>& rhs)
	{ return (lhs.base() != rhs.base()); };
}

#endif