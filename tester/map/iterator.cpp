/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:26:01 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 11:29:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

int main()
{
	NAME::map<int, std::string> map;
	
	map[2] = "pourquoi pas";
	map[35] = "jsb";
	map[1] = "HELLLOO";
	map[-67] = "hihihihihi";
	map[-67] = "NORMALEMENT JAMAIS ON VOIT CEC BIA LLA PCAR YA DEJA -67 WESH";
	map[352] = "dshrstrsthrsth";
	map[345] = "yessseijiu";
	map[3121] = "je mapekkreolle julien";
	map[12] = "jspa ecrir";
	map[-9789] = "toi meme";
	map[2] = "que d donn2 innutillls";
	map[4] = "o azar";
	map[76543] = "quel basard";
	map[12122] = "treihtetyiuertiuertiueriuyertyiuertiuertyertyiue hhvb dsrbvhueskuvbshb vuebrvervuyer  tres longue stirng????";
	map[322] = "eqwe";
	map[0] = "jsaddd";
	map[332324] = "jtadddb";
	map[5] = "j498797";
	map[876890] = "wqeqe";
	map[9] = "jdsss";
	map[8] = "jcxxc";
	map[456] = "fdeeerr";
	map[92] = "tyuiuyi";
	map[12] = "jhkhjk";
	map[3234] = "bvnddf";
	map[5] = "dwwwb";
	map[54] = "rtyuy";
	map[12] = "hgjl";
	map[32] = "llili";
	map[43] = "hjyui";
	map[985] = "hjyuyh";



	NAME::map<int, std::string>::iterator it = map.begin();
	NAME::map<int, std::string>::const_iterator cit = it;
	NAME::map<int, std::string>::reverse_iterator rit = map.rbegin();
	NAME::map<int, std::string>::iterator ite = map.end();
	NAME::map<int, std::string>::const_iterator cite = ite;
	NAME::map<int, std::string>::reverse_iterator rite = map.rend();

	print_map(map);
	for (;it != ite;it++)
	{
		std::cout << "Iterator normal                    : "; print_pair(it, true);
		std::cout << "Const Iterator(meme que le normal) : "; print_pair(cit++, true);
		std::cout << "Reverse iterator, pas le meme      : "; print_pair(rit++, true);
	}
	return (0);
}