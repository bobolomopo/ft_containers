/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:27:24 by jandre            #+#    #+#             */
/*   Updated: 2022/04/03 19:36:06 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "map.hpp"
#include "bst.hpp"
#include <map>

int main()
{
    ft::pair<int, int> p1(123, 124);
    ft::pair<int, int> p2(123123, 124);
    ft::pair<int, int> p3(1231, 124);
    ft::pair<int, int> p4(-23, 124);
    ft::pair<int, int> p5(-123, 124);
    ft::pair<int, int> p6(-11123, 124);
    ft::pair<int, int> p7(-8123, 124);
    ft::bst<ft::pair<const int, int>, const int> bst;
    ft::node<ft::pair<int, int>> *node;

    bst.insert(p1);
    bst.insert(p2);
    bst.insert(p3);
    bst.insert(p4);
    bst.insert(p5);
    bst.insert(p6);
    bst.insert(p7);
    ft::map<int, int>::iterator it(bst.get_root());
    ft::map<int, int>::iterator itf(it._first);
    ft::map<int, int>::iterator ite(it._last);
    while ((*itf) != (*ite))
    {
        std::cout << (*itf).first << std::endl;
        itf++;
    }
    return (0);
}