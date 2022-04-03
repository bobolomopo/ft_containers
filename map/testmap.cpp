/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:27:24 by jandre            #+#    #+#             */
/*   Updated: 2022/04/02 00:57:25 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "map.hpp"
#include <map>

int main()
{
    ft::map<int, int> map1;
    ft::map<int, int> map2;
    ft::map<int, int> map3;
    ft::map<int, int> map4;
    ft::pair<int, int> p1(123, 124);
    ft::map<int, int>::iterator it = map1.begin();
    ft::map<int, int>::iterator ite = map1.end();

    map1.insert(p1);
    std::cout << "begin " << (it != ite) << std::endl;
    std::cout << "end " << (*map1.end()).first << std::endl;
    std::cout << "begin " << (*map1.begin()).second << std::endl;
    std::cout << "end " << (*map1.end()).second << std::endl;
    return (0);
}