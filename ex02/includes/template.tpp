/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:46:24 by aptive            #+#    #+#             */
/*   Updated: 2023/03/16 18:09:56 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_TPP
#define TEMPLATE_TPP

# include <iostream>
# include <string>

# include <stack>
# include <list>
# include <vector>
# include <algorithm>

# include <cstring>
# include <unistd.h>
# include <stdlib.h>

# include <time.h>
# include <sys/time.h>


template <typename Container>
void affichage_container(const Container & l)
{
	for (typename Container::const_iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

long gettime(struct timeval start, struct timeval end);

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

template<typename T>
void sort_and_time_vector(std::vector<T> & v)
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	// code à mesurer
	std::sort(v.begin(), v.end());
	gettimeofday(&end, NULL);

	std::cout	<< "Time to process a range of : "<< v.size()
				<< " elements with std::[VECTOR] :	" << gettime(start, end) << " us." << std::endl;
}

template<typename T>
void sort_and_time_list(std::list<T> & l)
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	// code à mesurer
	l.sort();
	gettimeofday(&end, NULL);

	std::cout	<< "Time to process a range of : "<< l.size()
				<< " elements with std::[LIST] :	" << gettime(start, end) << " us." << std::endl;
	}


#endif //TEMPLATE_TPP
