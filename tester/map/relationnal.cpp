/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationnal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:58:03 by jandre            #+#    #+#             */
/*   Updated: 2022/04/07 13:01:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"

int main()
{
		NAME::map<std::string, int> map1;
		NAME::map<std::string, int> map2;
	
	map1["pourquoi pas"] = 2;
	map1["jsb"] = 213;
	map1["HELLLOO"] = 12;
	map1["hihihihihi"] = 32;
	map1["NORMALEMENT JAMAIS ON VOIT CEC BIA LLA PCAR YA DEJA -67 WESH"] = 123123;
	map1["dshrstrsthrsth"] = 123;
	map1["yessseijiu"] = 44444;
	map1["je mapekkreolle julien"] = 234234;
	map1["jspa ecrir"] = 5435345;
	map1["toi meme"] = 3455;
	map1["que d donn2 innutillls"] = 1222;
	map1["o azar"] = 99080;
	map1["quel basard"] = -9879;
	map1["treihtetyiuertiuertiueriuyertyiuertiuertyertyiue hhvb dsrbvhueskuvbshb vuebrvervuyer  tres longue stirng????"] = 567567567;
	map1["eqwe"] = 32321;
	map1["jsaddd"] = 5666;
	map1["jtadddb"] = 567876;
	map1["j498797"] = 99;
	map1["wqeqe"] = 456;
	map1["jdsss"] = 87876;
	map1["jcxxc"] = 867978;
	map1["fdeeerr"] = 99789;
	map1["tyuiuyi"] = 789567;
	map1["jhkhjk"] = 75634245;
	map1["bvnddf"] = 1123;
	map1["dwwwb"] = 43245;
	map2["rtyuy"] = 645745;
	map2["hgjl"] = 657;
	map2["llili"] = 7567;
	map2["hjyui"] = 567567;
	map2["hjyuyh"] = 7657;
	map2["hjyuyh"] = 7657;
	map2["hjyuyh"] = 7657;
	map2["hjyuyh"] = 7657;
	map2["zzzzzzzzzzzzzz1"] = 0;
	map2["zzzzzzzzzzzzz2"] = 0;
	map2["zzzzzzzzzzzz3"] = 0;
	map2["zzzzzzzzzzz4"] = 0;
	map2["zzzzzzzzzz5"] = 0;
	map2["zzzzzzzzz6"] = 0;
	map2["zzzzzzzz7"] = 0;
	map2["zzzzzzzz7"] = 0;
	map2["Aaaaaaaaa7"] = 0;
	map2["Aaaaaaa7"] = 0;
	map2["Aaaaaa7"] = 0;
	map2["Aaaaa7"] = 0;

	NAME::map<std::string, int> map3(map2);
	NAME::map<std::string, int> map4(map1);

	is_equal(map1, map2);
	is_equal(map4, map2);
	is_equal(map1, map4);
	is_equal(map2, map2);
	is_equal(map2, map3);

}