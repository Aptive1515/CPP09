/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:00 by aptive            #+#    #+#             */
/*   Updated: 2023/03/24 15:38:00 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rpn.hpp"
#include "../includes/template.tpp"

void calcul(std::stack<double> * s, char c)
{
	if (s->size() >= 2)
	{
		double nb_tmp1 = s->top();
		s->pop();
		double nb_tmp2 = s->top();
		s->pop();
		if (c == '/')
			s->push(nb_tmp2 / nb_tmp1);
		else if (c == 'x' || c == '*')
			s->push(nb_tmp1 * nb_tmp2);
		else if (c == '+')
			s->push(nb_tmp1 + nb_tmp2);
		else if (c == '-')
			s->push(nb_tmp2 - nb_tmp1);
	}
	else
		throw std::string("Error in arg !\n");
}

int main(int argc, char ** argv)
{
	std::stack<double> s;
	try
	{
		check_arg(argc, argv);
		for (size_t i = 0; argv[1][i]; i++)
		{
			if(isdigit(argv[1][i]))
				s.push(argv[1][i] - '0');
			else if (argv[1][i] == '/'
					|| argv[1][i] == 'x'
					|| argv[1][i] == '*'
					|| argv[1][i] == '+'
					|| argv[1][i] == '-')
				calcul(&s, argv[1][i]);
		}
		if (s.size() == 1)
			std::cout << s.top() << std::endl;
		else
			throw std::string("Error in result !\n");
	}
	catch(const std::string except)
	{
		std::cout << except;
	}
	return 0;
}
