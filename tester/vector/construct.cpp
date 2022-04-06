/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:51:26 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 17:27:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//to test the true container
#include <vector>
#include <iostream>

//to test mine
#include "../../vector/vector.hpp"
#include "base.hpp"
#define NAME ft
#define T1 int
#define T2 std::string

int main()
{

	NAME::vector<T1> vct1;
	print_vec(vct1);
	NAME::vector<T1>::iterator it = vct1.begin();
	for (int i = -34;  i < 150;i += 18)
		vct1.insert(it++, i);
	print_vec(vct1);
	
	NAME::vector<T1> vct2(vct1);
	print_vec(vct2);
	NAME::vector<T2> vct3(15, "TEST VECTOR");
	print_vec(vct3);
	NAME::vector<T2> vct4 = vct3;
	print_vec(vct4);
	vct4.insert(vct4.begin() + 7, 17, "replace");
	print_vec(vct4);
	vct3 = vct4;
	vct4.erase(vct4.begin() + 7, vct4.end());
	print_vec(vct4);
	print_vec(vct3);

	return (0);
}