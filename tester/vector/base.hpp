/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:26:28 by jandre            #+#    #+#             */
/*   Updated: 2022/04/06 19:02:10 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define NAME ft


template<typename T>
void print_vec(NAME::vector<T> vec)
{
	typename NAME::vector<T>::iterator it = vec.begin();
	typename NAME::vector<T>::iterator ite = vec.end();

	std::cout << "size : " << vec.size() << std::endl;
	std::cout << "content :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl << "#################################" << std::endl;
	std::cout << std::endl;
};

template <typename T>
void print_capacity(NAME::vector<T> vct)
{
	std::cout << "capacity :" << vct.capacity() << std::endl;
	std::cout << "size :" << vct.size() << std::endl;
	std::cout << "capacity :" << vct.max_size() << std::endl;
	std::cout << std::endl << "###########################" <<std::endl<<std::endl;
};

template <typename T>
void re_size(NAME::vector<T> vct, int re)
{
	std::cout << "before :" << std::endl;
	print_capacity(vct);
	vct.resize(re);
	std::cout << "after :" << vct.max_size() << std::endl;
	print_capacity(vct);
};

template <typename T>
void is_equal(NAME::vector<T> vct, NAME::vector<T> vct2)
{
	std::cout << "#####   try equal ope ... ######" << std::endl;
	std::cout << "is equal         : "<< (vct == vct2) << std::endl;
	std::cout << "is greater       : "<< (vct > vct2) << std::endl;
	std::cout << "is greater or eq : "<< (vct >= vct2) << std::endl;
	std::cout << "is lower         : "<< (vct < vct2) << std::endl;
	std::cout << "is lower or eq   : "<< (vct <= vct2) << std::endl;
	std::cout << "################################" <<std::endl << std::endl;
}