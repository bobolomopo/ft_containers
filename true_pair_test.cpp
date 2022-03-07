/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_pair_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:23:30 by jandre            #+#    #+#             */
/*   Updated: 2022/03/07 17:25:18 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>

int main()
{
    std::pair<int, std::string> a;
    std::pair<int, std::string> b(4, "colegue");
    std::pair<int, std::string> d(7, "debilos");

    std::cout << "=====================================================" << std::endl;
    std::cout << "|---------------------PAIR_TEST---------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "a pair : " << a.first << " " << a.second << std::endl;
    a = std::make_pair(19, "karaoke");
    std::cout << "a pair after make_pair : " << a.first << " " << a.second << std::endl;
    std::cout << "b pair : " << b.first << " " << b.second << std::endl;
    a = b;
    std::cout << "a pair after a = b : " << a.first << " " << a.second << std::endl;
    std::pair<int, std::string> c(a);
    std::cout << std::endl << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "|------------PAIR_RELATIONAL_OPERATORTEST------------|" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "c pair after calling std::pair<int, std::string> c(a) : " << c.first << " " << c.second << std::endl;
    std::cout << "d pair : " << d.first << " " << d.second << std::endl;
    std::cout << "is c < d ? : " << (c < d) << std::endl;
    std::cout << "is c > d ? : " << (c > d) << std::endl;
    std::cout << "is c <= d ? : " << (c <= d) << std::endl;
    std::cout << "is c >= d ? : " << (c >= d) << std::endl;
    std::cout << "is c == d ? : " << (c == d) << std::endl;
    std::cout << "c pair : " << c.first << " " << c.second << std::endl;
    std::cout << std::endl << std::endl;
    return 0;

}