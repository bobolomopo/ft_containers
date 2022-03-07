/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:25:36 by jandre            #+#    #+#             */
/*   Updated: 2022/03/07 18:38:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

static void print_vec_values(ft::vector<int> vec)
{
        for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
}

int main()
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "|-------------VECTOR_TEST_CONSTRUCTOR---------------|" << std::endl;
    std::cout << "=====================================================" << std::endl  << std::endl;

    ft::vector<int> vec_int; 
    ft::vector<int> vec_base_val(10, 465); 
    ft::vector<int> vec_cpy(vec_base_val); 
    ft::vector<int> vec_int2(vec_base_val.begin(), vec_base_val.begin() + 3); 
    
    std::cout << "=====================================================" << std::endl;
    std::cout << "|-----------------PRINT_BASE_VALUES------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    print_vec_values(vec_int);
    print_vec_values(vec_base_val);
    print_vec_values(vec_cpy);
    print_vec_values(vec_int2);

    return (0);
}