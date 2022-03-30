/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:37:15 by jandre            #+#    #+#             */
/*   Updated: 2022/03/29 15:42:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <utility>

int main()
{
    std::map<std::string, int> map;

    map.insert(std::pair<std::string, int>("premier test", 324));
    map.insert(std::pair<std::string, int>("prsqdt", 21));
    map.insert(std::pair<std::string, int>("prem&ést", 3));
    map.insert(std::pair<std::string, int>("premier test", 123));
    map.insert(std::pair<std::string, int>("deuxieme", 3));
    for (std::map<std::string,int>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << (it->first) << " " << it->second << std::endl;
    return (0);
}