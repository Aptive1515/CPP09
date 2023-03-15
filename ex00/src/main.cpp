/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/15 15:13:38 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"



int main(int argc, char ** argv)
{
	std::map<std::string, double> mapData;
	std::string dataFile = "data.csv";

	try
	{
		check_arg(argc, argv);
		mapData = open_and_check_conf_file(dataFile, ',');
		serch_and_print(mapData, argv[1]);
	}
	catch(const std::string except)
	{
		std::cout << except;
	}
	return 0;
}
