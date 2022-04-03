/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:33:19 by jandre            #+#    #+#             */
/*   Updated: 2022/04/02 01:00:54 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP
# include <memory>
# include "node.hpp"
# include "bst_it.hpp"
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
			typedef T											value_type;
			typedef typename ft::bst_it<value_type>                iterator;

        private:
            node_type   		*_root;
			node_allocator_type	_node_alloc;
        
        public:
		//Constructor && Destructor
            bst(const node_allocator_type &node_alloc_init = node_allocator_type()) : _node_alloc(node_alloc_init), _root(NULL)
			{
				_root = _node_alloc.allocate(1);
				_node_alloc.construct(_root, node_type());
			};
			~bst()
			{
				/*iterator it(_root);
				iterator tmp(it._first);
				node_type *tmp_data;

				while (tmp._node->_data.first != it._last->_data.first)
				{
					tmp_data = tmp._node;
					tmp++;
					remove(tmp_data);
				}
				remove(tmp._node->_data);*/
			}
            //Accessor to root to construct iterators
			node_type *get_root() { return (_root); };
			bool empty() { return (_root == NULL); };
			iterator insert(iterator hint, value_type value)
			{
				value_type	cmp;
				value_type	cmp_parent;
				node_type	*base_node_hint = hint._node;
				bool		correct_place;

				if (hint._node->_parent == NULL || hint._node == NULL)
					return (this->insert(value));
				cmp = hint._node->_data;
				cmp_parent = hint._node->_parent->_data;
				correct_place = false;
				//check the place, while parents are lesser or greater keep going.
				//if we get to the root then the place is ok to place the new node there
				//if the value of the parent node is greater than the last parent
				//and the value is lesser than this parents node's data or the contrary
				//, its ok, if not, its not ok and call the normal insert function.
				if (cmp < value)
				{
					while (hint._node->_parent != NULL && cmp > cmp_parent)
					{
						hint._node = hint._node->_parent;
						cmp = hint._node->_data;
						cmp_parent = hint._node->_parent->_data;
					}
					if (hint._node->_parent == NULL || cmp_parent > value)
						correct_place = true;
				}
				else if (cmp > value)
				{
					while (hint._node->_parent != NULL || cmp < cmp_parent)
					{
						cmp = hint._node->_data;
						cmp_parent = hint._node->_parent->_data;
						hint._node = hint._node->_parent;
					}
					if (hint._node->_parent == NULL || cmp_parent < value)
						correct_place = true;
				}
				//if the place is true, do the same as the insert(value_type) function
				//but begins from the hint node instead of the root, else just calls
				//the normal function
				if (correct_place == true)
				{
					node_type* t = _node_alloc.allocate(1);
					node_type* parent;
					t->_data.first = value.first;
					t->_data.second = value.second;
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
						tmp = base_node_hint;
						// Find the Node's parent
						while (tmp)
						{
							parent = tmp;
							if (t->_data.first > tmp->_data.first)
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
					iterator it(t);
					return (it);
				}
				else
					return (this->insert(value));
			};
            iterator insert(value_type new_value)
            {
                node_type* t = _node_alloc.allocate(1);
                node_type* parent;
                t->_data.first = new_value.first;
				t->_data.second = new_value.second;
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
						if (t->_data.first > tmp->_data.first)
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
				iterator it(t);
				return (it);
            };
			node_type *search_by_key(value_type to_search)
			{
				node_type *tmp = _root;

				while (tmp)
				{
					if (tmp->_data.first > to_search.first)
						tmp = tmp->_left;
					else if (tmp->_data.first < to_search.first)
						tmp = tmp->_right;
					else
						return (tmp);
				}
				return (tmp);
			};
			bool remove(value_type to_remove)
			{
				bool found = false;

				if (this->empty())
					return (found);
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
					return (found);
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
					return (found);
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
					return (found);
				}
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
					return (found);
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
				}
				return (found);
			};
    };
}

#endif