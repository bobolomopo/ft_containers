/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_real.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:58:52 by jandre            #+#    #+#             */
/*   Updated: 2022/03/07 17:59:33 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

static void print_vec_values(std::vector<int> vec)
{
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
}

int main()
{
    std::cout << "=====================================================" << std::endl;
    std::cout << "|-------------VECTOR_TEST_CONSTRUCTOR---------------|" << std::endl;
    std::cout << "=====================================================" << std::endl  << std::endl;

    std::vector<int> vec_int; 
    std::vector<int> vec_base_val(10, 465); 
    std::vector<int> vec_cpy(vec_base_val); 
    std::vector<int> vec_int2(vec_base_val.begin(), vec_base_val.begin() + 3); 
    
    std::cout << "=====================================================" << std::endl;
    std::cout << "|-----------------PRINT_BASE_VALUES------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    print_vec_values(vec_int);
    print_vec_values(vec_base_val);
    print_vec_values(vec_cpy);
    print_vec_values(vec_int2);

    return (0);
}