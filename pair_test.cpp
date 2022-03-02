#include "pair.hpp"
#include <iostream>

int main()
{
    ft::pair<int, std::string> a;
    ft::pair<int, std::string> b(4, "colegue");
    ft::pair<int, std::string> d(7, "debilos");

    std::cout << "=====================================================" << std::endl;
    std::cout << "|---------------------PAIR_TEST---------------------|" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "a pair : " << a.first << " " << a.second << std::endl;
    a = ft::make_pair(19, "karaoke");
    std::cout << "a pair after make_pair: " << a.first << " " << a.second << std::endl;
    std::cout << "b pair : " << b.first << " " << b.second << std::endl;
    a = b;
    std::cout << "a pair after a = b: " << a.first << " " << a.second << std::endl;
    ft::pair<int, std::string> c(a);
    std::cout << std::endl << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "|------------PAIR_RELATIONAL_OPERATORTEST------------|" << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "c pair after calling ft::pair<int, std::string> c(a) : " << c.first << " " << c.second << std::endl;
    std::cout << "d pair : " << d.first << " " << d.second << std::endl;
    std::cout << "is c < d ? : " << (c < d) << std::endl;
    std::cout << "is c > d ? : " << (c > d) << std::endl;
    std::cout << "is c <= d ? : " << (c <= d) << std::endl;
    std::cout << "is c >= d ? : " << (c >= d) << std::endl;
    std::cout << "is c == d ? : " << (c == d) << std::endl;
    std::cout << "c pair : " << c.first << " " << c.second << std::endl;
    std::cout << std::endl << std::endl;
    return 0;

}