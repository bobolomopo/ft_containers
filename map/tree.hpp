/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:14:59 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 15:54:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "tree_iterator.hpp"
# include "../utils/reverse_iterator.hpp"

namespace ft {
    template <class T, class Compare, class Allocator>
	class tree
    {
        public:
            typedef T													        value_type;
            typedef Compare												        key_compare;
            typedef Allocator											        allocator_type;
        private:
            typedef typename value_type::first_type								key_type;
            typedef typename allocator_type::template rebind<Node<T> >::other	node_allocator;
            typedef typename node_allocator::reference							node_reference;
            typedef typename node_allocator::const_reference					node_const_reference;
            typedef typename node_allocator::difference_type					node_difference_type;
            typedef typename node_allocator::pointer							alloc_node_pointer;
            typedef typename node_allocator::const_pointer						alloc_node_const_pointer;
            typedef typename node_allocator::size_type							node_size_type;
            typedef Node<value_type>											node_type;
			typedef Node<const value_type>										const_node_type;
            typedef node_type *                                                 node_pointer;
			typedef const_node_type *											const_node_pointer;

        public:
            typedef typename allocator_type::reference							reference;
            typedef typename allocator_type::const_reference					const_reference;
            typedef typename allocator_type::difference_type					difference_type;
            typedef typename allocator_type::pointer							pointer;
            typedef typename allocator_type::const_pointer						const_pointer;
            typedef typename allocator_type::size_type							size_type;
            typedef ft::tree_it<node_type, value_type>							iterator;
            typedef ft::tree_it<node_type, const value_type>					const_iterator;
            typedef ft::reverse_iterator<iterator>								reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
        
        private:
            node_pointer        _root;
            size_t              _size;
            key_compare         _comp;
            node_allocator      _alloc;
            node_pointer        _end;

        public:
        //Constructors && Destructors
            tree(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
                : _size(0), _comp(comp), _alloc(alloc)
            {
                this->_end = this->_alloc.allocate(1);
                this->_end->left = NULL;
                this->_end->right = NULL;
                this->_end->parent = NULL;
                this->_root = this->_end;
            };
            ~tree() 
            {
                if (this->size())
                    this->clear();
                this->_alloc.deallocate(this->_end, 1);
		    };

		//Iterators && const_iterators
			iterator begin()				        	{ return (iterator(this->get_min(this->_root))); };
			const_iterator begin() const	        	{ return (const_iterator((this->get_min(this->_root)))); };
			iterator end()					        	{ return (iterator(this->_end)); }
			const_iterator end() const		        	{ return (const_iterator((this->_end))); }

		//Reverse iterators and const_reverse iterators
			reverse_iterator rbegin()		        	{ return (reverse_iterator(this->_end)); };
			const_reverse_iterator rbegin() const		{ return (const_reverse_iterator((this->_end))); };
			reverse_iterator rend()			        	{ return (reverse_iterator(this->get_min(this->_root))); };
			const_reverse_iterator rend() const	    	{ return (const_reverse_iterator((this->get_min(this->_root)))); };

		//Size and allocator
			bool empty() const			            	{ return (this->_size == 0); };
			size_type size() const			        	{ return (this->_size); };
			size_type max_size() const		        	{ return (node_allocator().max_size()); };
			node_allocator get_allocator() const		{ return (this->_alloc); };
		//Accessors
			node_pointer get_end() const				{ return (this->_end); };
			
		//Initialize a new node with any value
			node_pointer init_node(value_type data)
			{
				node_pointer node = this->_alloc.allocate(1);
				this->_alloc.construct(node, data);
				node->parent = NULL;
				node->left = NULL;
				node->right = NULL;
				return (node);
			};
		//Inserting a new node in the tree
			void insert(const value_type &val)
			{
				this->_root = add_node(this->_root, this->_root, val, val.first);
				this->get_max(this->_root)->right = this->_end; //set the end after the biggest value
				this->_end->parent = this->get_max(this->_root);
			};
			node_pointer insert_hint(node_pointer position, const value_type &val) 
			{
				node_pointer tmp = position;
				
				//Check if it is at the good place in the tree
				if (this->_comp(tmp->data.first, val.first)) //if the val is lower than the hinted position, goes until a parent is greater, see if the val is lesser than it too
				{
					tmp = tmp->parent;
					while (tmp->parent && this->_comp(tmp->data.first, tmp->parent->data.first))
						tmp = tmp->parent;
					if (tmp->data.first == val.first)
						return (tmp);
					if (tmp != _root && this->_comp(tmp->parent->data.first, val.first))
						return (add_node(this->_root, this->_root, val, val.first));
				}
				else if (this->_comp(val.first, tmp->data.first)) // does the contrary than above, if it goes to the root, it means its ok
				{
					tmp = tmp->parent;
					while (tmp->parent && this->_comp(tmp->parent->data.first, tmp->data.first))
						tmp = tmp->parent;
					if (tmp->data.first == val.first)
						return (tmp);
					if (tmp != _root && this->_comp(val.first, tmp->parent->data.first))
						return (add_node(this->_root, this->_root, val, val.first));
				}
				node_pointer ret = add_node(position, position, val, val.first);
				if (this->_root->parent)
					this->_root = this->_root->parent;
				add_node(this->_root, this->_root, val, val.first);
				this->get_max(this->_root)->right = this->_end;
				this->_end->parent = this->get_max(this->_root);
				return (get_successor(ret));
			};
		//finding a particular key in the tree
			bool is_found(key_type key) const			{ return (this->is_found_helper(this->_root, key)); };
			node_pointer find(key_type key) const
			{
				if (!this->is_found(key))
					return this->_end;
				return (find_helper(this->_root, key));
			};
			
		//all the deletion related functions
			void delete_node(key_type key)       		{ this->_root = this->delete_node_helper(this->_root, key); };
			void clear()
			{
				delete_tree(this->_root);
				this->_end->parent = NULL;
				this->_root = this->_end;
				this->_size = 0;
			};
		//All the boundaries related functions
		//Return the first elements whose key is not greater than key in the tree
			node_pointer lower_bound(key_type key) const
			{
				node_pointer temp = this->get_min(this->_root);
				
				if (temp == NULL || temp == this->_end)
					return (this->_end);
				while (temp->data.first <= key) //while data is < than key, get successor
				{
					if (key == temp->data.first)
						break ;
					temp = get_successor(temp);
					if (temp == NULL || temp == this->_end)
						return (this->_end); //if there is not result, return the end node
				}
				return (temp);
			};
			/*const_node_pointer const_lower_bound(key_type key) const
			{
				return (to_const(lower_bound(key)));
			}*/
			node_pointer upper_bound(key_type key) const
			{
				node_pointer temp = this->get_min(this->_root);
				if (temp == NULL || temp == this->_end)
					return (this->_end);
				while (temp->data.first <= key) //while data is > than key, get successor
				{
					temp = get_successor(temp);
					if (temp == NULL || temp == this->_end)
						return (this->_end); //if there is not result, return the end node
				}
				return (temp);
			};
			/*const_node_pointer const_upper_bound(key_type key) const
			{
				return (to_const(upper_bound(key)));
			}*/
		//swap values of two tress
			void	swap(tree& x) 
			{
				size_t			temp_size = x._size;
				node_pointer	temp_root = x._root;
				node_pointer	temp_end = x._end;
				node_allocator	temp_alloc = x._alloc;
				key_compare		temp_comp = x._comp;

				x._size = this->_size;
				x._root = this->_root;
				x._end = this->_end;
				x._alloc = this->_alloc;
				x._comp = this->_comp;

				this->_size = temp_size;
				this->_root = temp_root;
				this->_end = temp_end;
				this->_alloc = temp_alloc;
				this->_comp = temp_comp;
			};
			
		private: //All Helpers functions aka not needed outside the class
		//Getting biggest and lowest key value		
			node_pointer get_max(node_pointer node) const
			{
				while (node->right != NULL && node->right != this->_end)
					node = node->right;
				return (node);
			};
			node_pointer get_min(node_pointer node) const 
			{
				while (node->left != NULL && node != this->_end)
					node = node->left;
				return (node);
			};
		//deleting all the tree, from the node in paramater, putting root
		//deletes all the tree
			void delete_tree(node_pointer node)
			{
				if (node == NULL || node == this->_end)
					return ;
				delete_tree(node->left);
				delete_tree(node->right);
				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
				node = NULL;
			};
		//deleting one node, and rearranging the tree
			node_pointer delete_node_helper(node_pointer node, key_type key)
			{
				if (node == NULL || node == this->_end)
					return (node);	//when the node is the end or is not found
				if (this->_comp(key, node->data.first)) 
					node->left = delete_node_helper(node->left, key);
				else if (this->_comp(node->data.first, key))
					node->right = delete_node_helper(node->right, key); //going trough the node to find the one to delete
				else //the node to delete was found
				{
					if (node->left == NULL && node->right == NULL) //the node to delete doenst have any child
					{
						this->_alloc.destroy(node);
						this->_alloc.deallocate(node, 1);
						this->_size--;
						node = NULL;
					}
					else if (node->left == NULL) //only has a right child
					{
						node_pointer temp = node;
						node = node->right;
						if (node)
							node->parent = temp->parent;
						this->_alloc.destroy(temp);
						this->_alloc.deallocate(temp, 1);
						this->_size--;
						temp = NULL;
					}
					else if (node->right == NULL) //only has a left child
					{
						node_pointer temp = node;
						node = node->left;
						if (node)
							node->parent = temp->parent;
						this->_alloc.destroy(temp);
						this->_alloc.deallocate(temp, 1);
						this->_size--;
						temp = NULL;
					}
					else //has two child
					{
						node_pointer temp = this->get_min(node->right); //getting the lowest(?) node after the right node
						node_pointer new_node = init_node(temp->data);
						new_node->parent = node->parent;
						if (node->parent) //if node is not the root
						{
							if (node == node->parent->right) //if node is greater or lesser than his parent
								node->parent->right = new_node;
							else
								node->parent->left = new_node;
						}
						new_node->left = node->left;
						node->left->parent = new_node; //deleted node is replaced by the lowest node at his right
						new_node->right = delete_node_helper(node->right, temp->data.first); //deleting the lowest node at his right
						if (new_node->right)
							new_node->right->parent = new_node;
						node = new_node;
					}
				}
				return (node);
			};
		//find helpers
			node_pointer find_helper(node_pointer node, key_type key) const
			{
				if (node == NULL)
					return node;
				else if (this->_comp(key, node->data.first))
					return (find_helper(node->left, key));
				if (this->_comp(node->data.first, key))
					return (find_helper(node->right, key));
				else
					return (node);
			};
			bool is_found_helper(node_pointer node, key_type key) const
			{
				if (node == NULL || node == this->_end)
					return (false);
				else if (this->_comp(key, node->data.first))
					return (is_found_helper(node->left, key));
				if (this->_comp(node->data.first, key))
					return (is_found_helper(node->right, key));
				else
					return (true);
			};
		//Add a node with the value value and key key from the pointer node to the tree
			node_pointer add_node(node_pointer node, node_pointer parent, value_type val, key_type key)
			{
				if (node == NULL || node == this->_end) //if tree is empty or we are at the place to add it
				{
					node_pointer ret = init_node(val);
					if (parent != this->_end)
						ret->parent = parent;
					this->_size++;
					return (ret);
				}
				if (this->_comp(key, node->data.first))
					node->left = add_node(node->left, node, val, key);
				else if (this->_comp(node->data.first, key))
					node->right = add_node(node->right, node, val, key); //iterate trough the tree from the initial node (usually root))
				return (node); //return the node found or added
			};
    };
	//getting  lowest node
	template <class node_pointer>
	node_pointer get_min(node_pointer node) 
	{
		while (node->left != NULL)
			node = node->left;
		return (node);
	};
	//getting biggest node
	template <class node_pointer>
	node_pointer get_max(node_pointer node) 
	{
		while (node->right != NULL)
			node = node->right;
		return (node);
	};
	//getting next node value wise
	template <class node_pointer>
	node_pointer get_successor(node_pointer node) 
	{
		if (node->right)
			return get_min(node->right);
		node_pointer	temp = node->parent;
		while (temp && node == temp->right) {
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	};
	//getting last node value wise
	template <class node_pointer>
	node_pointer get_predecessor(node_pointer node) 
	{
		if (node->left)
			return get_max(node->left);
		node_pointer	temp = node->parent;
		while (temp && node == temp->left) {
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	};
}

#endif