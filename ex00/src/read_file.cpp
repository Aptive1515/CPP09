/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:19:55 by aptive            #+#    #+#             */
/*   Updated: 2023/03/15 15:13:44 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"


double stringtodouble(std::string value)
{
	return static_cast<double>(std::strtod(value.c_str(), NULL));
}

std::pair<std::string, double> parse_to_pair (std::string str, char c)
{
	std::string s1;
	std::string s2;

	int i = -1;
	while ( ++i < static_cast<int>(str.size()) && str[i] != c)
		if (str[i] != ' ')
			s1.append(str, i, 1);

	// std::cout << s1 << std::endl;
	while ( str[++i] )
		if (str[i] != ' ')
			s2.append(str, i, 1);
	std::pair<std::string, double> my_pair = std::make_pair(s1, stringtodouble(s2));
	return my_pair;
}

std::map<std::string, double> open_and_check_conf_file(std::string file, char c)
{
	std::ifstream	flux(file.c_str());
	std::map<std::string, double> list_conf;
	std::string line;


	if (!flux.is_open())
		throw std::string("Error : Unable to open the file !\n");
	while (!flux.eof() && getline(flux, line))
	{
		if (!line.empty() && line.find(c) != std::string::npos )
			list_conf.insert(parse_to_pair(line, c));
	}
	return list_conf;
}

int check_valid_format(std::string str)
{
	std::string format = "XXXX-XX-XX | ";
	size_t j(0);

	for (size_t i = 0; i < format.size() ; i++)
	{
		if (format[i] == 'X' && !isdigit(str[i]))
			return 0;
		else if ((format[i] == '-' || format[i] == '|' || format[i] == ' ') && format[i] != str[i])
			return 0;
		j = i;
	}
	j++;
	size_t count = 0;
	for (size_t i = j; i < str.size(); i++)
	{
		if (str[j] == '-')
			i++;
		else if (str[i] == '.')
			count++;
		else if (!isdigit(str[i]))
			return 0;
		if (count > 1)
			return 0;
	}
	return 1;
}

void serch_and_print(std::map<std::string, double> mapData, std::string file)
{
	std::ifstream	flux(file.c_str());
	std::string line;
	std::pair <std::string, double> myPair;
	char c = '|';

	if (!flux.is_open())
		throw std::string("Error : Unable to open the file !\n");
	while (!flux.eof() && getline(flux, line))
	{
		if (!line.empty())
		{
			if (!check_valid_format(line))
				std::cout << "Error: bad input => " << line << std::endl;
			else
			{
				myPair = parse_to_pair(line, c);
				std::map<std::string, double>::iterator it = mapData.lower_bound(myPair.first);
				if (myPair.second < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (myPair.second > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
					std::cout << it->first << " => "<< it->second * myPair.second << std::endl;

			}
		}
	}
}
