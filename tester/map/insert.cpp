/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:29:13 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 12:51:37 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

int main()
{
	NAME::map<std::string, int> map;
	
	map["pourquoi pas"] = 2;
	map["jsb"] = 213;
	map["HELLLOO"] = 12;
	map["hihihihihi"] = 32;
	map["NORMALEMENT JAMAIS ON VOIT CEC BIA LLA PCAR YA DEJA -67 WESH"] = 123123;
	map["dshrstrsthrsth"] = 123;
	map["yessseijiu"] = 44444;
	map["je mapekkreolle julien"] = 234234;
	map["jspa ecrir"] = 5435345;
	map["toi meme"] = 3455;
	map["que d donn2 innutillls"] = 1222;
	map["o azar"] = 99080;
	map["quel basard"] = -9879;
	map["treihtetyiuertiuertiueriuyertyiuertiuertyertyiue hhvb dsrbvhueskuvbshb vuebrvervuyer  tres longue stirng????"] = 567567567;
	map["eqwe"] = 32321;
	map["jsaddd"] = 5666;
	map["jtadddb"] = 567876;
	map["j498797"] = 99;
	map["wqeqe"] = 456;
	map["jdsss"] = 87876;
	map["jcxxc"] = 867978;
	map["fdeeerr"] = 99789;
	map["tyuiuyi"] = 789567;
	map["jhkhjk"] = 75634245;
	map["bvnddf"] = 1123;
	map["dwwwb"] = 43245;
	map["rtyuy"] = 645745;
	map["hgjl"] = 657;
	map["llili"] = 7567;
	map["hjyui"] = 567567;
	map["hjyuyh"] = 7657;
	map["hjyuyh"] = 7657;
	map["hjyuyh"] = 7657;
	map["hjyuyh"] = 7657;
	map["zzzzzzzzzzzzzz1"] = 0;
	map["zzzzzzzzzzzzz2"] = 0;
	map["zzzzzzzzzzzz3"] = 0;
	map["zzzzzzzzzzz4"] = 0;
	map["zzzzzzzzzz5"] = 0;
	map["zzzzzzzzz6"] = 0;
	map["zzzzzzzz7"] = 0;
	map["zzzzzzzz7"] = 0;
	map["Aaaaaaaaa7"] = 0;
	map["Aaaaaaa7"] = 0;
	map["Aaaaaa7"] = 0;
	map["Aaaaa7"] = 0;
	
	print_map(map);
	//NAME::map<std::string, int> map_cpy(map.begin(), map.begin() + 10); should error
	NAME::map<std::string, int>::iterator it = map.begin();
	for (int i = 0; i < 10; i++)
		it++;
	NAME::map<std::string, int> map_cpy(map.begin(), it);
	print_map(map_cpy);
	map.erase(map.begin(), it);
	print_map(map);
	it = map_cpy.begin();
	for (int i = 0; i < 10; i++)
		it++;
	map.insert(map_cpy.begin(), it);
	print_map(map);
	it = map_cpy.begin();
	for (int i = 0; i < 2; i++)
		it++;

	map.clear();
	print_map(map);
	std::cout << it->first << std::endl;
	map.insert(*it);
	it++;
	map.insert(*it);
	it++;
	map.insert(*it);
	it++;
	map.insert(--it, *it);
	print_map(map);
	print_map(map_cpy);
	map.swap(map_cpy);
	print_map(map);
	print_map(map_cpy);
}
