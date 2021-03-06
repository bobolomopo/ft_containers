/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:07:54 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 16:14:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include <list>

#define T1 int
#define T2 int
typedef NAME::pair<const T1, T2> T3;

int main()
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	NAME::map<T1, T2> mp(lst.begin(), lst.end());
	NAME::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	NAME::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	NAME::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	print_map(mp);
	print_map(mp_range);
	print_map(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	print_map(mp);
	print_map(mp_range);
	print_map(mp_copy);
	return (0);
}