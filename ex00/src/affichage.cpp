/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:23:07 by aptive            #+#    #+#             */
/*   Updated: 2023/03/14 18:56:12 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

void affichage_map(std::map<std::string, double>  map)
{
	int i = 0;
	for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); it++)
	{
		i++;
		std::cout << "list " << i << " < " << it->first << ", " << it->second << " >"<< std::endl;
	}
}
