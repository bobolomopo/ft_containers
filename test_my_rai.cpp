/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_my_rai.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:18:50 by jandre            #+#    #+#             */
/*   Updated: 2022/03/22 18:58:36 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>

int main()
{
    int tmp[5] = {0, 1, 42, 3, 4};
    int tmp2[5] = {123, -21, 53, 21, 7};

    std::cout << "=====================================================" << std::endl;
    std::cout << "|------------ITERATOR_TEST_CONSTRUCTOR--------------|" << std::endl;
    std::cout << "=====================================================" << std::endl  << std::endl;

    ft::random_access_iterator<int> it(tmp);
    ft::random_access_iterator<int> it2(tmp2);
    ft::random_access_iterator<int> it_cpy(tmp);

    std::cout << "all good!!" << std::endl << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "|--------------ITERATOR_TEST_BOOLEAN----------------|" << std::endl;
    std::cout << "=====================================================" << std::endl  << std::endl;

    std::cout << "is it == it_cpy : " << (it == it_cpy) << std::endl;
    std::cout << "is it == it2 : " << (it == it2) << std::endl;
    std::cout << "is it >= it2 : " << (it >= it2) << std::endl;
    std::cout << "is it <= it2 : " << (it <= it2) << std::endl;
    std::cout << "is it < it2 : " << (it < it2) << std::endl;
    std::cout << "is it > it2 : " << (it > it2) << std::endl << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "|---------------ITERATOR_TEST_VALUE-----------------|" << std::endl;
    std::cout << "=====================================================" << std::endl  << std::endl;

    std::cout << "it : ( ";
    for (int i = 0; i < 5; i++)
        std::cout << it[i] << " ";
    std::cout << ")" << std::endl;
    std::cout << "it_cpy : ( ";
    for (int i = 0; i < 5; i++)
        std::cout << *(it_cpy + i) << " ";
    std::cout << ")" << std::endl;
    std::cout << "it2 : ( ";
    for (int i = 0; i < 5; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << ")" << std::endl;
    it2 = it;
    std::cout << "it2 after the equal : ( ";
    for (int i = 0; i < 5; i++)
        std::cout << *(it2 + i) << " ";
    std::cout << ")" << std::endl << std::endl;
    return 0;
}