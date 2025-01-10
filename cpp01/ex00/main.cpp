/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:14 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/10 15:52:19 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//apparement stack
	randomChump("MONSTRE");
	std::cout << std::endl;

	//apparement heap ( mais pourquoi different de random chump ???)
	Zombie *Zed;
	Zed = newZombie("Zed");
	Zed->announce();
	delete Zed;
	return (0);
}