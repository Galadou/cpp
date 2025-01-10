/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:53 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/10 16:10:46 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-ketchup burger." << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*debugPtr[4])() = { // tableau de pointeur vers fonctions membre 
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
	};

	//je cree un tableau qui contien les string dans le bon ordre
	//(si c'est info, alors c'est le deuxieme dans mon tableau vers fonc pt)
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level_tab[i] == level)
		{
			(this->*debugPtr[i])(); // on appel la bonne fonction membre !
			return;
		}
	}
	std::cerr << "Error: wrong level entered" << std::endl;
}