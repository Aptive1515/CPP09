/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:19:35 by aptive            #+#    #+#             */
/*   Updated: 2023/03/16 16:58:10 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rpn.hpp"

void check_arg(int argc, char ** argv)
{
	if (argc != 2)
		throw std::string("Error : Wrong number of arguments !\n");

	for (size_t i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] == ' ')
			i++;
		if (!isdigit(argv[1][i])
			&& argv[1][i] != '/'
			&& argv[1][i] != '*'
			&& argv[1][i] != 'x'
			&& argv[1][i] != '+'
			&& argv[1][i] != '-')
			throw std::string("Error : Wrong char in arg !\n");
		if (isdigit(argv[1][i]) && isdigit(argv[1][i + 1]))
			throw std::string("Error : Wrong char in arg !\n");
	}
}
