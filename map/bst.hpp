/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:33:19 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 02:10:17 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP
# include <memory>
# include "node.hpp"
# include <functional>
# include <iostream>

namespace ft {
	template <class T, class Node = ft::node<T>,
	class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class bst
    {
		public:
			typedef Type_Alloc	allocator_type;
            typedef Node_Alloc  node_allocator_type;
            typedef Node        node_type;
			typedef T			value_type;

        private:
            node_type   		*_root;
			node_allocator_type	_node_alloc;
        
        public:
		//Constructor && Destructor
            bst() : _root() {};
            
			bool empty() { return (_root == NULL); };
            void insert(value_type new_value)
            {
                node_type* t = _node_alloc.allocate(1);
                node_type* parent;
                t->_data.first = new_value.first;
                t->_left = NULL;
                t->_right = NULL;
				t->_parent = NULL;
                parent = NULL;
				
				//if its empty the new node is the root
				//if not, find the place where the node is placed
				if (this->empty())
					_root = t;
				else
				{
					node_type *tmp;
					tmp = _root;
					// Find the Node's parent
					while (tmp)
					{
						parent = tmp;
						if(t->_data.first > tmp->_data.first)
							tmp = tmp->_right;
						else
							tmp = tmp->_left;
					}
					if (t->_data.first < parent->_data.first)
					{
						t->_parent = parent;
						parent->_left = t;
					}
					else
					{
						t->_parent = parent;
						parent->_right = t;
					}
				}
            };
			void remove(value_type to_remove)
			{
				bool found = false;
				if(this->empty())
					return ;
				node_type *tmp;
				node_type *parent;
				tmp = _root;
				while (tmp)
				{
					if (tmp->_data.first == to_remove.first)
					{
						found = true;
						break ;
					}
					else
					{
						parent = tmp;
						if (to_remove.first > tmp->_data.first)
							tmp = tmp->_right;
						else
							tmp = tmp->_left;
					}
				}
				if (!found)
					return ;
				// Node has a single child and node is the root
				if ((tmp == _root && tmp->_left == NULL && tmp->_right != NULL) || (tmp == _root && (tmp->_left != NULL && tmp->_right == NULL)))
				{
					if (tmp->_left == NULL && tmp->_right != NULL)
					{
						_root = tmp->_right;
						tmp->_right->_parent = NULL;
						_node_alloc.deallocate(tmp, 1);
					}
					else
					{
						_root = tmp->_left;
						tmp->_left->_parent = NULL;
						_node_alloc.deallocate(tmp, 1);
					}
				}
				//node has a single child but is not the root
				if ((tmp->_left == NULL && tmp->_right != NULL) || (tmp->_left != NULL && tmp->_right == NULL))
				{
					if (tmp->_left == NULL && tmp->_right != NULL)
					{
						if (parent->_left == tmp)
						{
							parent->_left = tmp->_right;
							tmp->_right->_parent = parent;
							_node_alloc.deallocate(tmp, 1);
						}
						else
						{
							parent->_right = tmp->_right;
							tmp->_right->_parent = parent;
							_node_alloc.deallocate(tmp, 1);
						}
					}
					else // left child present, no right child
					{
						if (parent->_left == tmp)
						{
							parent->_left = tmp->_left;
							tmp->_left->_parent = parent;
							_node_alloc.deallocate(tmp, 1);
						}
						else
						{
							parent->_right = tmp->_left;
							tmp->_left->_parent = parent;
							_node_alloc.deallocate(tmp, 1);
						}
					}
					return;
				};
				// The node to remove doesnt have any child
				if( tmp->_left == NULL && tmp->_right == NULL)
				{
					if (tmp->_parent)
					{
						if (parent->_left == tmp)
							parent->_left = NULL;
						else
							parent->_right = NULL;
					}
					_node_alloc.deallocate(tmp, 1);
					return;
				}
				//The node to remove has two childs
				if (tmp->_left != NULL && tmp->_right != NULL)
				{
					node_type *check_right;
					node_type *check_left;
					check_right = tmp->_right;
					check_left = tmp->_left;
					if ((check_right->_left == NULL) && (check_right->_right == NULL))
					{
						//the right node doesn't have any children
						if (tmp->_parent)
							check_right->_parent = tmp->_parent;
						else
						{
							_root = check_right;
							check_right->_parent = NULL;
						}
						tmp = check_right;
						_node_alloc.deallocate(check_right, 1);
						tmp->_right = NULL;
					}
					else if ((check_left->_left == NULL) && (check_left->_right == NULL))
					{
						//the left node doesn't have any children
						if (tmp->_parent)
							check_left->_parent = tmp->_parent;
						else
						{
							_root = check_left;
							check_left->_parent = NULL;
						}
						tmp = check_left;
						_node_alloc.deallocate(check_left, 1);
						tmp->_left = NULL;
					}
					else // right child and left child have children
					{
						//if the node's right child has a left child
						//Move all the way down left to locate smallest element
						if ((tmp->_right)->_left != NULL)
						{
							node_type *last_to_left;
							node_type *first_to_right;
							first_to_right = tmp->_right;
							last_to_left = (tmp->_right)->_left;
							while (last_to_left->_left != NULL)
							{
								first_to_right = last_to_left;
								last_to_left = last_to_left->_left;
							}
							if (tmp->_parent)
								last_to_left->_parent = tmp->_parent;
							else
							{
								_root = last_to_left;
								last_to_left->_parent = NULL;
							}
							tmp = last_to_left;
							_node_alloc.deallocate(last_to_left, 1);
							first_to_right->_left = NULL;
						}
						else
						{
							node_type *next;
							next = tmp->_right;
							if (tmp->_parent)
								next->_parent = tmp->_parent;
							else
							{
								_root = next;
								next->_parent = NULL;
							}
							_node_alloc.deallocate(tmp, 1);
						}
					}
					return;
				}
			};
    };
}

#endif