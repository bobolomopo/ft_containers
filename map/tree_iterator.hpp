/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:59:14 by jandre            #+#    #+#             */
/*   Updated: 2022/04/05 15:43:38 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "../utils/iterator_traits.hpp"

namespace ft {
    template <class T, class Node>
	class tree_it : public ft::iterator<std::bidirectional_iterator_tag, T> 
	{
		public:
			typedef T												iterator_type;
			typedef typename std::bidirectional_iterator_tag		iterator_category;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef  Node											node_pointer;
		private:
			node_pointer _node;
		
		public:
			tree_it() : _node() {};
			explicit tree_it(node_pointer node) : _node(node) {};
			template <class Iter>
			tree_it(const tree_it<Iter, node_pointer>& copy) : _node(copy.base()) {};

			node_pointer	base() const		{ return this->_node; };
			reference		operator*() const	{ return this->_node->data; };
			tree_it&		operator++()		{ this->_node = get_successor(this->_node); return (*this); };
			tree_it			operator++(int)		{ tree_it temp(*this); ++(*this); return (temp); };
			tree_it&		operator--()		{ this->_node = get_predecessor(this->_node); return (*this); };
			tree_it			operator--(int)		{ tree_it temp(*this); --(*this); return (temp); };
			pointer			operator->() const	{ return (&(operator*())); };
	};
	template <class Iterator, class Node>
	bool	operator==(const tree_it<Iterator, Node>& lhs, const tree_it<Iterator, Node>& rhs)
	{ return (lhs.base() == rhs.base()); };
	template<typename T_L, typename T_R, class KeyType>
    bool operator==(const tree_it<T_L, KeyType> lhs,
              const tree_it<T_R, KeyType> rhs)
	{ return (lhs.base() == rhs.base()); };
	template <class Iterator, class Node>
	bool	operator!=(const tree_it<Iterator, Node>& lhs, const tree_it<Iterator, Node>& rhs)
	{ return (lhs.base() != rhs.base()); };
	template<typename T_L, typename T_R, class KeyType>
    bool operator!=(const tree_it<T_L, KeyType> lhs,
              const tree_it<T_R, KeyType> rhs)
	{ return (lhs.base() != rhs.base()); };
}

#endif