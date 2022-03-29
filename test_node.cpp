/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_node.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:43:09 by jandre            #+#    #+#             */
/*   Updated: 2022/03/29 16:48:10 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree_node.hpp"
#include "pair.hpp"
#include <iostream>

int main()
{
    ft::bst_node<int, int> root(ft::pair<int, int>(124, 42));
    ft::bst_node<int, int> second(ft::pair<int, int>(12, 12312), &root);
    ft::bst_node<int, int> third(ft::pair<int, int>(-123, 12312), &root);
    ft::bst_node<int, int> fourth(ft::pair<int, int>(1444343, 12312), &root);
    ft::bst_node<int, int> fifth(ft::pair<int, int>(144, 12312), &root);
    ft::bst_node<int, int> sixth(ft::pair<int, int>(1, 12312), &root);

    //std::cout << second._parent->_data.first << std::endl;
    //std::cout << third._parent->_data.first << std::endl;
    std::cout << fourth._parent->_data.first << std::endl;
    //std::cout << fifth._parent->_data.first << std::endl;
    //std::cout << sixth._parent->_data.first << std::endl;
}