/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_real.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:25:36 by jandre            #+#    #+#             */
/*   Updated: 2022/03/23 16:16:21 by jandre           ###   ########.fr       */
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
    std::vector<int> vec_base_val(10, 10); 
    std::vector<int> vec_cpy(vec_base_val); 
    std::vector<int> vec_int2(vec_base_val.begin(), vec_base_val.begin() + 3); 
    std::cout << "All good !!!" << std::endl << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "|-----------------PRINT_BASE_VALUES------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    std::cout << "vec_int : "; print_vec_values(vec_int);
    std::cout << "vec_base_val : "; print_vec_values(vec_base_val);
    std::cout << "vec_cpy : "; print_vec_values(vec_cpy);
    std::cout << "vec_int2 : "; print_vec_values(vec_int2);
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "|------------------TEST_FUNCTIONS-------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    std::cout << "size : " << vec_base_val.size() << std::endl;
    std::cout << "max_size : " << vec_base_val.max_size() << std::endl;
    vec_base_val.resize(5, 10);
    std::cout << "resize to 5 and calling size : " << vec_base_val.size() << std::endl;
    vec_base_val.resize(10, 5);
    std::cout << "resize to 10 and calling size : " << vec_base_val.size() << std::endl;
    std::cout << "checking if the value is 5 for the resized container : "; print_vec_values(vec_base_val);
    std::cout << "begin : " << *(vec_base_val.begin()) << std::endl;
    std::cout << "r_begin : " << *(vec_base_val.rbegin()) << std::endl;
    std::cout << "end : " << *(vec_base_val.end()) << std::endl;
    std::cout << "r_end : " << *(vec_base_val.rend()) << std::endl;
    std::cout << "capacity : " << vec_base_val.capacity() << std::endl;
    std::cout << "is_empty to a non empty container : " << vec_base_val.empty() << std::endl;
    std::cout << "is_empty to an empty container : " << vec_int.empty() << std::endl;
    vec_base_val.reserve(30);
    std::cout << "reserve 30 and then calling capacity and size : " << vec_base_val.capacity() << " , size : " << vec_base_val.size() << std::endl;
    vec_base_val.assign(8, 1269);
    std::cout << "checking if the value is 1269 and the size is 8 after assign : "; print_vec_values(vec_base_val);
    std::cout << "size : " << vec_base_val.size() << std::endl;
    std::cout << "capacity : " << vec_base_val.capacity() << std::endl;
    vec_base_val.assign(vec_cpy.begin(), vec_cpy.end());
    std::cout << "checking if the value are the same as the begining after assign with iterators : "; print_vec_values(vec_base_val);
    std::cout << "size : " << vec_base_val.size() << std::endl;
    std::cout << "capacity : " << vec_base_val.capacity() << std::endl;
    vec_base_val.push_back(100000);
    std::cout << "push_back 100000 : "; print_vec_values(vec_base_val);
    vec_base_val.pop_back();
    std::cout << "pop_back : "; print_vec_values(vec_base_val);
    vec_base_val.insert(vec_base_val.begin() + 4, 123456);
    std::cout << "insert 123456 at the 5th position : "; print_vec_values(vec_base_val);
    vec_base_val.insert(vec_base_val.begin() + 4, 4, 934);
    std::cout << "insert 4 times 934 from the 5th position : "; print_vec_values(vec_base_val);
    vec_base_val.insert(vec_base_val.begin() + 5, vec_cpy.begin(), vec_cpy.end());
    std::cout << "insert the range 10 times 10 from vec_int from the 6nd position : "; print_vec_values(vec_base_val);
    std::cout << "size : " << vec_base_val.size() << std::endl;
    vec_base_val.erase(vec_base_val.begin() + 4);
    std::cout << "checking that the erase range fonction returns the correct iterator : " << *(vec_base_val.erase(vec_base_val.begin() + 14, vec_base_val.begin() + 19)) << std::endl;
    std::cout << "erase at the 5th position and from the 15th to the 20th position (all the 934 and the 123456) : "; print_vec_values(vec_base_val);
    std::cout << "size : " << vec_base_val.size() << std::endl;
    vec_int.assign(4, 120);
    std::cout << "before the swap : " << std::endl;
    std::cout << "vec_int : "; print_vec_values(vec_int);
    std::cout << "vec_base_val : "; print_vec_values(vec_base_val);
    vec_base_val.swap(vec_int);
    std::cout << "after the swap : " << std::endl;
    std::cout << "vec_int : "; print_vec_values(vec_int);
    std::cout << "vec_base_val : "; print_vec_values(vec_base_val);
    vec_base_val.clear();
    std::cout << "vec_base_val after clear : "; print_vec_values(vec_base_val);
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "|---------------TEST_POSITION_GETTER----------------|" << std::endl;
    std::cout << "=====================================================" << std::endl << std::endl;

    vec_int.push_back(42);
    std::cout << "vec_base_val : "; print_vec_values(vec_int);
    std::cout << "front : " << vec_int.front() << std::endl;
    std::cout << "back : " << vec_int.back() << std::endl;
    try 
    {
        std::cout << "at correct : " << vec_int.at(2) << std::endl;
        std::cout << "at exeption : " << vec_int.at(200) << std::endl;
    }
    catch (std::out_of_range(&e))
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}