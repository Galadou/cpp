/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:01 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:24:02 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int N = 10;
	Zombie *horde;
	
	horde = zombieHorde(N, "OUI");

	int i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}