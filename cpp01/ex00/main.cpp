/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:14 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/11 13:51:11 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//stack
	randomChump("MONSTRE");
	std::cout << std::endl;

	//heap
	Zombie *Zed;
	Zed = newZombie("Zed");
	Zed->announce();
	delete Zed;

	return (0);
}