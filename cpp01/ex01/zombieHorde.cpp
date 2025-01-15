/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:09 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/15 17:38:46 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *horde;

	if (N < 1)
	{
		std::cout << "Error: bad number of zombies" << std::endl;
		return (NULL);
	}
	horde = new (std::nothrow)Zombie [N];
	if(!horde)
	{
		std::cout << "Allocation error" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}                          