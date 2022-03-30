/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:33:19 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 01:04:52 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP
# include <memory>
# include "node.hpp"
# include "bst_it.hpp"
# include <functional>

namespace ft {
	template <class T, class Compare = std::less<T>, class Node = ft::node<T>,
	class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class bst
    {
		public:
			typedef Type_Alloc	allocator_type;
            typedef Node_Alloc  node_allocator_type;
            typedef Node        node_type;
            typedef Compare     comp;
			typedef T			value_type;

        private:
            node_type   *_root;
        
        public:
		//Constructor && Destructor
            bst() : _root() {};
            
			bool empty() { return (_root == NULL); };
            void insert(value_type new_value)
            {
                node_type* t = node_allocator_type.allocate(1);
                node_type* parent;
                t->_data.first = new_value;
                t->_left = NULL;
                t->_right = NULL;
				t->_parent = NULL;
				t->_root = root;
                parent = NULL;
				
				//if its empty the new node is the root
				//if not, find the place where the node is placed
				if (this->empty())
				{
					_root = t;
					t->_root = t;
				}
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
							tmp = tmp->right;
						else
							tmp = tmp->left;
					}
				}
				if (!found)
					return ;
				// Node has a single child
				if ((tmp->_left == NULL && tmp->_right != NULL) || (tmp->_left != NULL && tmp->_right == NULL))
				{
					if (tmp->_left == NULL && tmp->_right != NULL)
					{
						if (parent->left == tmp)
						{
							parent->left = tmp->right;
							tmp->_right->_parent = parent;
							node_allocator_type.deallocate(tmp);
						}
						else
						{
							parent->_right = tmp->_right;
							tmp->_right->_parent = parent;
							node_allocator_type.deallocate(tmp);
						}
					}
					else // left child present, no right child
					{
						if (parent->_left == tmp)
						{
							parent->_left = tmp->_left;
							tmp->_left->_parent = parent;
							node_allocator_type.deallocate(tmp);
						}
						else
						{
							parent->_right = tmp->_left;
							tmp->_left->_parent = parent;
							node_allocator_type.deallocate(tmp);
						}
					}
					return;
				};
				// The node to remove doesnt have any child
				if( tmp->_left == NULL && tmp->_right == NULL)
				{
					if(parent->_left == tmp)
						parent->_left = NULL;
					else
						parent->_right = NULL;
					node_allocator_type.deallocate(tmp);
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
						check_right->_parent = tmp->_parent;
						tmp = check_right;
						node_allocator_type.deallocate(check_right);
						tmp->_right = NULL;
					}
					else if ((check_left->_left == NULL) && (check_left->_right == NULL))
					{
						//the left node doesn't have any children
						check_left->_parent = tmp->_parent;
						tmp = check_left;
						node_allocator_type.deallocate(check_left);
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
							last_to_left->_parent = tmp._parent;
							tmp = last_to_left;
							node_allocator_type.deallocate(last_to_left);
							first_to_right->left = NULL;
						}
						else
						{
							node_type *next;
							*next = *(tmp->right);
							next->_parent = tmp->_parent;
							node_allocator_type.deallocate(tmp);
						}
					}
					return;
				}

			};
            void print_inorder();
            void inorder(node*);
            void print_preorder();
            void preorder(node*);
            void print_postorder();
            void postorder(node*);
            void remove(int);
    };
}

#endif