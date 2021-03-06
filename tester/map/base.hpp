/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:08:22 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 16:15:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# if !defined(USING_STD)
#  define NAME ft
# else
#  define NAME std
# endif /* !defined(STD) */

//to test mine
#include "../../map/map.hpp"
#include <iostream>
#include <map>
#include <string>

template <typename T>
void is_equal(T map1, T map2)
{
	std::cout << "#####   try equal ope ... ######" << std::endl;
	std::cout << "is equal         : "<< (map1 == map2) << std::endl;
	std::cout << "is greater       : "<< (map1 > map2) << std::endl;
	std::cout << "is greater or eq : "<< (map1 >= map2) << std::endl;
	std::cout << "is lower         : "<< (map1 < map2) << std::endl;
	std::cout << "is lower or eq   : "<< (map1 <= map2) << std::endl;
	std::cout << "################################" <<std::endl << std::endl;
}

template <typename T>
std::string	print_pair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
};

template <typename T_MAP>
void	print_map(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << print_pair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
};

template <typename T1, typename T2>
void	print_reverse(NAME::map<T1, T2> &mp)
{
	typename NAME::map<T1, T2>::reverse_iterator it = mp.rbegin(), ite = mp.rend();

	std::cout << "print_reverse:" << std::endl;
	while (it != ite) {
		it++;
		std::cout << "-> " << print_pair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
};
