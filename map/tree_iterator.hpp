/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:59:14 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 07:04:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "../utils/iterator_traits.hpp"

namespace ft {
	template <class T>
	class Node {
	public:
		T		data;
		Node*	parent;
		Node*	left;
		Node*	right;
		Node*	end;

		Node(T new_data) : data(new_data) {};
	};
    template <class T>
	class tree_it : public ft::iterator<ft::bidirectional_iterator_tag, T> 
	{
		public:
			typedef T																						value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category 			iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type				difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type					value_type_traits;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference						reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer						pointer;
			typedef  ft::Node<value_type> *																	node_pointer;
		private:
			node_pointer _node;
		
		public:
			tree_it() : _node() {};
			tree_it(node_pointer node) : _node(node) {};
			tree_it(const tree_it &copy) : _node(copy.base()) {};
			tree_it &operator=(const tree_it &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			};
			virtual ~tree_it() {};

			node_pointer base() const		{ return (this->_node); };
			reference operator*() const		{ return (this->_node->data); };
			tree_it& operator++()			{ this->_node = get_successor(this->_node); return (*this); };
			tree_it operator++(int)			{ tree_it temp(*this); ++(*this); return (temp); };
			tree_it& operator--()			{ this->_node = get_predecessor(this->_node); return (*this); };
			tree_it operator--(int)			{ tree_it temp(*this); --(*this); return (temp); };
			pointer operator->() const		{ return (&(operator*())); };
	};

	template <class T>
	bool	operator==(const tree_it<T>& lhs, const tree_it<T>& rhs)
	{ return (lhs.base() == rhs.base()); };
	template<typename T_L, typename T_R>
    bool operator==(const tree_it<T_L> lhs,
              const tree_it<T_R> rhs)
	{ return (lhs.base() == rhs.base()); };
	
	template <class T>
	bool	operator!=(const tree_it<T>& lhs, const tree_it<T>& rhs)
	{ return (lhs.base() != rhs.base()); };
	template<typename T_L, typename T_R>
    bool operator!=(const tree_it<T_L> lhs,
              const tree_it<T_R> rhs)
	{ return (lhs.base() != rhs.base()); };
}

#endif