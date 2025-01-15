/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:09:13 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/15 17:45:55 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _hisWeapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack() const
{
	if (this->_hisWeapon == NULL)
	{
		std::cout << this->_name << " has no weapon, but try to attack..." << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their " << this->_hisWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_hisWeapon = &newWeapon;
}