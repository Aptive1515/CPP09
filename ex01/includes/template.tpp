/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:46:24 by aptive            #+#    #+#             */
/*   Updated: 2023/03/16 16:45:20 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_TPP
#define TEMPLATE_TPP

#include <iostream>
#include <stack>

template <typename Container>
void affichage_container(const Container & l)
{
	int i = 0;
	for (typename Container::const_iterator it = l.begin(); it != l.end(); it++)
	{
		i++;
		std::cout << "list " << i << " < " << *it << " >" << std::endl;
	}
}

template<typename T>
void affichage_stack(const std::stack<T> & pile)
{
	int i = 0;
	std::stack<T> copie_pile = pile;
	std::cout << "-----------------------------\n";
	while(!copie_pile.empty())
	{
		i++;
		std::cout << "Element " << i << " : " << copie_pile.top() << std::endl;
		copie_pile.pop();
	}
	std::cout << "-----------------------------\n";

}
#endif //TEMPLATE_TPP
