/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationnal_ope.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:49:21 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 15:53:48 by jandre           ###   ########.fr       */
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
	NAME::vector<T1> vct;
	NAME::vector<T1> vct2(12, 2);
	NAME::vector<T1> vct3(19, 2);
	NAME::vector<T1> vct4(vct3);

	for (int i = 0; i < 20 ; i++)
		vct.push_back(i * 2);
	NAME::vector<T2> vct_std1;

	vct_std1.insert(vct_std1.end(), 5, "NOT OK LOL");
	vct_std1.insert(vct_std1.end(), 5, "POLOLO");
	vct_std1.insert(vct_std1.end(), 5, "PITOU");
	NAME::vector<T2> vct_std2(vct_std1);

	is_equal(vct_std1, vct_std2);
	is_equal(vct, vct2);
	is_equal(vct, vct3);
	is_equal(vct4, vct2);
	is_equal(vct3, vct);
	is_equal(vct4, vct);
	is_equal(vct3, vct2);
	is_equal(vct3, vct4);


}