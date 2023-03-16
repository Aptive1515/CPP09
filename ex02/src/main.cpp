/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/16 18:10:41 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include "../includes/template.tpp"


long gettime(struct timeval start, struct timeval end)
{
	long seconds = end.tv_sec - start.tv_sec;
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	return micros;
}

int main(int argc, char ** argv)
{
	(void)argc;
	(void)argv;

	std::vector<int> v_temoin;
	std::vector<int> v;
	std::list<int> l;

	try
	{

		check_arg(argc, argv);

		for (int i = 1; argv[i]; i++)
		{
			v.push_back(atoi(argv[i]));
			l.push_back(atoi(argv[i]));
		}

		v_temoin = v;
		std::cout << "BEFORE : ";
		affichage_container(v_temoin);
		std::sort(v_temoin.begin(), v_temoin.end());
		std::cout << "AFTER :  ";
		affichage_container(v_temoin);

		// -------------------------------- VECTOR -------------------------------------;
		sort_and_time_vector(v);

		// --------------------------------- LIST -------------------------------------;
		sort_and_time_list(l);
	}
	catch(const std::string except)
	{
		std::cout << except;
	}





	return 0;
}
