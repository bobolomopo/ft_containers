/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_bst.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:11:52 by jandre            #+#    #+#             */
/*   Updated: 2022/03/31 01:45:28 by jandre           ###   ########.fr       */
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
    p test_pair1(42, 42);
    p test_pair2(32, 42);
    p test_pair3(1, 42);
    p test_pair4(222, 42);
    p test_pair5(-123, 42);
    p test_pair6(3231, 42);
    p test_pair7(1234, 42);
    p test_pair8(41, 42);

    std::cout << test.empty() << std::endl;
    test.insert(test_pair);
    test.insert(test_pair1);
    test.insert(test_pair2);
    test.insert(test_pair3);
    test.insert(test_pair4);
    test.insert(test_pair5);
    test.insert(test_pair6);
    test.insert(test_pair7);
    std::cout << test.empty() << std::endl;
    test.remove(test_pair);
    std::cout << test.empty() << std::endl;


}