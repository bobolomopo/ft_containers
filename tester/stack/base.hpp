/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:56:26 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 15:43:32 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
# if !defined(USING_STD)
#  define NAME ft
# else
#  define NAME std
# endif /* !defined(STD) */


//to test the true container
#include <stack>
#include <iostream>

//to test mine
#include "../../stack/stack.hpp"

template <typename T_STACK>
void	print_stack(T_STACK &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "#################################" << std::endl;
}

#endif