/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:59:19 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 18:08:50 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to test the true container
#include <vector>
#include <iostream>

//to test mine
#include "../../vector/vector.hpp"
#include "base.hpp"
#define T1 int
#define T2 std::string

int main()
{
	NAME::vector<T2> vct(10, "OK");
	vct.insert(vct.end(), 5, "NOT OK LOL");
	vct.insert(vct.end(), 5, "POLOLO");
	vct.insert(vct.end(), 5, "PITOU");

	NAME::vector<T2>::iterator it = vct.begin();
	NAME::vector<T2>::const_iterator cit = vct.begin();
	NAME::vector<T2>::reverse_iterator rit = vct.rbegin();
	NAME::vector<T2>::const_reverse_iterator crit = vct.rbegin();

	int i = 0;
	while (it != vct.end())
	{
		std::cout << "====" << i << "===="<<std::endl;
		std::cout << "it normal : " <<*it << std::endl;
		std::cout << "const it  : "<<*cit << std::endl;
		std::cout << "rev it    : "<<*cit << std::endl;
		std::cout << "const rit : "<<*crit << std::endl;
		it++; cit++; rit++; crit++; i++;
	}

	it = vct.begin();
	//crit = it; //should error
	cit = it; //no error
}