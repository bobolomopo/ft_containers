/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_bst.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:11:52 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 03:21:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.hpp"
#include "../utils/pair.hpp"
#include <iostream>

int main()
{
    typedef ft::pair<int, int> p;
    ft::bst<ft::pair<int, int>> test;
    p test_pair(42, 42);
    p test_pair2(32, 42);
    p test_pair3(1, 42);
    p test_pair4(222, 42);
    p test_pair5(-123, 42);
    p test_pair6(3231, 42);
    p test_pair7(-412423, 42);
    p test_pair8(41, 42);

    ft::bst<ft::pair<int, int>>::iterator it;

    test.insert(test_pair);
    test.insert(test_pair2);
    test.insert(test_pair3);
    test.insert(test_pair4);
    test.insert(test_pair5);
    test.insert(test_pair6);
    it = test.insert(test_pair7);
    while (it._node != it._last)
    {
        std::cout << (*it).first << std::endl;
        it++;
    }
    std::cout << (*it).first << std::endl;
    std::cout << std::endl << std::endl;
}