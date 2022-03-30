/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:40 by jandre            #+#    #+#             */
/*   Updated: 2022/03/21 16:34:41 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {
    //The type T is enabled as member type enable_if::type if Cond is true.
    //Otherwise, enable_if::type is not defined.
    //This is useful to hide signatures on compile time when a particular condition is not met,
    //since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.

    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
}

#endif