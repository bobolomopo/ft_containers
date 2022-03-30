/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:29:12 by jandre            #+#    #+#             */
/*   Updated: 2022/03/21 18:19:21 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {
    //base form of the structure that will inherit the is_integral struct
    template <bool is_integral, typename T>
    struct is_integral_base 
    {
        typedef T type;
        static const bool value = is_integral;
    };
    //base form that the struct will take if type T is not an integral from the list
    template <typename>
        struct is_integral_type : public is_integral_base<false, bool> {};
    //Every override of every type that is an integral from the list
    template <>
        struct is_integral_type<bool> : public is_integral_base<true, bool> {};
    template <>
        struct is_integral_type<char> : public is_integral_base<true, char> {};
    template <>
        struct is_integral_type<signed char> : public is_integral_base<true, signed char> {};
    template <>
        struct is_integral_type<short int> : public is_integral_base<true, short int> {};
    template <>
        struct is_integral_type<int> : public is_integral_base<true, int> {};
    template <>
        struct is_integral_type<long int> : public is_integral_base<true, long int> {};
    template <>
        struct is_integral_type<long long int> : public is_integral_base<true, long long int> {};
    template <>
        struct is_integral_type<unsigned char> : public is_integral_base<true, unsigned char> {};
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_base<true, unsigned short int> {};
    template <>
        struct is_integral_type<unsigned int> : public is_integral_base<true, unsigned int> {};
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_base<true, unsigned long int> {};
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_base<true, unsigned long long int> {};
    //final form of is_integral, inherit from is_integral_type and override the correct way depending of T
     template <typename T>
        struct is_integral : public is_integral_type<T> { };
}

#endif