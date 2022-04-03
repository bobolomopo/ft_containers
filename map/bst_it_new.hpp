/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_it_new.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:08:43 by jandre            #+#    #+#             */
/*   Updated: 2022/04/03 17:19:22 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_IT
# define BST_IT
# include "../utils/iterator_traits.hpp"

namespace ft {
	template <typename T, class Compare>
	class bst_it : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
		//All thhe typedef with iterator heritage
			typedef typename T::value_type    value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		
		private:
			T *			_node;
			T *			_last_node;
			Compare     _comp;
		
		public:
		//Constructor && destructors
			bst_it(const Compare& comp = Compare()) : _node(), _last_node(), _comp(comp) {};
			bst_it(T * node_p, T * last_node, const Compare& comp = Compare()) : _node(node_p), _last_node(last_node), _comp(comp) {};
			bst_it(const bst_it& bst_it) : _node(bst_it._node), _last_node(bst_it._last_node), _comp() {};
			virtual ~bst_it() {};
		//operators overloads
			bst_it &operator=(const bst_it& rhs)
			{
				if (*this == rhs)
					return (*this);
				this->_node = rhs._node;
				this->_last_node = rhs._last_node;
				this->_comp = rhs._comp;
				return (*this);
			};
			bool operator==(const bst_it& rhs) { return (this->_node == rhs._node); };
			bool operator!=(const bst_it& rhs) { return (this->_node != rhs._node); };
			bst_it& operator++(void)
			{
				T* tmp = _node;

				if (_node->right == _last_node)
				{
					tmp = _node->parent;
					while (tmp != _last_node && _comp(tmp->value.first, _node->value.first))
						tmp = tmp->parent;
					_node = tmp;
				}
				else if (tmp == _last_node)
					_node = _last_node->right;
				else
				{
					tmp = _node->right;
					if (tmp == _last_node->parent
						&& tmp->right == _last_node)
						_node = tmp;
					else
					{
						while (tmp->left != _last_node)
							tmp = tmp->left;
					}
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
				T* tmp = _node;

				if (_node->left == _last_node)
				{
					tmp = _node->parent;
					while (tmp != _last_node
						&& !_comp(tmp->value.first, _node->value.first))
						tmp = tmp->parent;
					_node = tmp;
				}
				else if (tmp == _last_node)
					_node = _last_node->right;
				else
				{
					tmp = _node->left;
					if (tmp == _last_node->parent
						&& tmp->left == _last_node)
						_node = tmp;
					else
					{
						while (tmp->right != _last_node)
							tmp = tmp->right;
					}
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
			//Reference and dereference
			reference operator*() const { return (this->_node->value); };
			pointer operator->() const { return (&this->_node->value); };	
	};
}

#endif