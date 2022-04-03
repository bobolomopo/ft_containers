/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_new.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:54:25 by jandre            #+#    #+#             */
/*   Updated: 2022/04/03 17:35:34 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP
# include "../utils/iterator_traits.hpp"
# include "bst_node_new.hpp"
# include "bst_it_new.hpp"
# include <utility>
# include "../utils/pair.hpp"

namespace ft {
    template <class T, class KeyType, class Compare = std::less<T>, class Node = ft::node<T>, class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class bst
	{
		public :
			typedef bst								self;
			typedef self							&self_reference;
			typedef T								value_type;
			typedef KeyType							key_type;
			typedef Node							node_type;
			typedef Node *							node_pointer;
			typedef Node_Alloc						node_alloc;
			typedef ft::bst_it<Node, Compare>		iterator;
			typedef ft::bst_it<const Node, Compare>	const_iterator;
			typedef size_t							size_type;

			node_pointer    _last_node;
			node_alloc      _node_alloc;
			
			bst (const node_alloc& node_alloc_init = node_alloc()) : _node_alloc(node_alloc_init)
			{
				_last_node = _node_alloc.allocate(1);
				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			};
			~bst ()
			{
				_node_alloc.destroy(_last_node);
				_node_alloc.deallocate(_last_node, 1);
			};

			ft::pair<iterator, bool> insert_pair(value_type to_insert)
			{
				node_pointer new_node = _node_alloc.allocate(1);
				node_pointer prev_node = _last_node;
				node_pointer start_node = _last_node->parent;
				bool side = true;
				
				while (start_node != _last_node)
				{
					key_type current_key = start_node->value.first;
					if (current_key == to_insert.first)
						return (ft::make_pair(iterator(start_node, _last_node), false));
					prev_node = start_node;
					if (to_insert.first > current_key)
					{
						side = true;
						start_node = start_node->right;
					}
					else
					{
						side = false;
						start_node = start_node->left;
					}
				}
				_node_alloc.construct(new_node, node_type(to_insert, prev_node, _last_node, _last_node));
				
				if (prev_node == _last_node)
					_last_node->parent = new_node;
				else if (side == true)
					prev_node->right = new_node;
				else
					prev_node->left = new_node;
				
				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first += 1;
				return (ft::make_pair(iterator(new_node, _last_node), true));
			}
}

#endif