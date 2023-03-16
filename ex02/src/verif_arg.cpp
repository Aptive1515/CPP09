/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:19:35 by aptive            #+#    #+#             */
/*   Updated: 2023/03/16 18:21:22 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void check_arg(int argc, char ** argv)
{
	if (argc < 2)
		throw std::string("Error : Wrong number of arguments !\n");

	for (int i = 1; argv[i]; i++)
	{
		if (!argv[i][0])
			throw std::string("Error : Empty arg");

		for (int j = 0; argv[i][j]; j++)
			if (!isdigit(argv[i][j]))
				throw std::string("Error : Wrong type of arg");
		std::string str = argv[i];
		if (str.size() > 2 && atoi(argv[i])  == - 1)
			throw std::string("Error : Max int");

	}
}
