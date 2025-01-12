/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:53 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/12 17:09:33 by gmersch          ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-ketchup burger." << std::endl;
	std::cout << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	void (Harl::*debugPtr[4])() = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
	};
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (i = 0; i < 4; i++)
	{
		if (level_tab[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*debugPtr[0])();
		case 1:
			(this->*debugPtr[1])();
		case 2:
			(this->*debugPtr[2])();
		case 3:
			(this->*debugPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}