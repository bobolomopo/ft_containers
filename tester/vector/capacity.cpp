/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:28:29 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 18:59:07 by jandre           ###   ########.fr       */
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
	NAME::vector<T1> vct(123, 2);
	NAME::vector<T2> vct_empty;
	std::cout << "is empty ? " << vct.empty() << std::endl;
	std::cout << "is empty ? " << vct_empty.empty() << std::endl;
	print_capacity(vct);
	re_size(vct, 34);
	print_capacity(vct);
	vct.push_back(100000);
	print_vec(vct);
	re_size(vct, 2);
	print_capacity(vct);
	vct.push_back(1200);
	print_capacity(vct);
	vct.pop_back();
	print_capacity(vct);

	NAME::vector<T1> vct2(10, 0);
	vct.swap(vct);
	print_vec(vct2);
	print_vec(vct);
	vct.clear();
	print_vec(vct);
	std::cout << vct[3] << "   " << vct[10] << std::endl;
	std::cout << vct[2] << "   " << vct[11] << std::endl;
	std::cout << vct[39] << "   " << vct[0] << std::endl;
	std::cout << vct[7] << "   " << vct[123] << std::endl;
	std::cout << vct[1] << "   " << vct[1] << std::endl;
	//std::cout << vct[1233] << std::endl; 	//ne renvoie pas dexception avec valeur aleatoire
	//std::cout << vct.at(12333) << std::endl; //refuse plus exception
}