/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:43:09 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 01:11:39 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree_node.hpp"
#include "binary_search_tree_iterator.hpp"
#include "pair.hpp"
#include <functional>
#include <iostream>

void test(ft::bst_node<ft::pair<int, int>> *root)
{
    ft::bst_it<ft::pair<int, int>, std::less<>> it(root);
    ft::bst_it<ft::pair<int, int>, std::less<>> it2(it._first);

    while ((it2->first != 1444343))
    {
        std::cout << (*it2).first << std::endl;
        it2++;
    }
    return ;
}

int main()
{
    ft::bst_node<ft::pair<int, int>> root(ft::pair<int, int>(120, 42));
    ft::bst_node<ft::pair<int, int>> second(ft::pair<int, int>(12, 12312), &root);
    ft::bst_node<ft::pair<int, int>> third(ft::pair<int, int>(-123, 12312), &root);
    ft::bst_node<ft::pair<int, int>> fourth(ft::pair<int, int>(1444343, 12312), &root);
    ft::bst_node<ft::pair<int, int>> fifth(ft::pair<int, int>(144, 12312), &root);
    ft::bst_node<ft::pair<int, int>> sixth(ft::pair<int, int>(1, 12312), &root);

    test(&root);
    //ft::bst_node<ft::pair<int, int>> seventh(ft::pair<int, int>(1, 122312), &root);

   /*ft::bst_it<ft::pair<int, int>, std::less<>> it(&third);
    int i = 0;

    while ((it->first != 1444343))
    {
        std::cout << (*it).first << std::endl;
        it++;
    }
    std::cout << (*it).first << std::endl;
    std::cout << &(*it) << std::endl;
    it++;
    std::cout << &(*it) << std::endl;
    it--;
    while ((it->first != -123) && i < 10)
    {
        std::cout << (*it).first << std::endl;
        it--;
        i++;
    }
    std::cout << (*it).first << std::endl;
    std::cout << "root" << std::endl;
    std::cout << root._right->_data.first << " " << root._right->_data.second << std::endl;
    std::cout << root._left->_data.first << " " << root._left->_data.second << std::endl;
    std::cout << "second" << std::endl;
    std::cout << second._parent->_data.first << " " << second._parent->_data.second << std::endl;
    std::cout << second._left->_data.first << " " << second._left->_data.second << std::endl;
    std::cout << "fourth" << std::endl;
    std::cout << fourth._parent->_data.first << " " << fourth._parent->_data.second << std::endl;
    std::cout << fourth._left->_data.first << " " << fourth._left->_data.second << std::endl;
    std::cout << "third" << std::endl;
    std::cout << third._parent->_data.first << " " << third._parent->_data.second << std::endl;
    std::cout << third._right->_data.first << " " << third._right->_data.second << std::endl;*/

}