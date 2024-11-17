/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:09:13 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:25:30 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//constructor
HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

//destructor
HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack() const
{
		std::cout << this->_name << " attacks with their " << this->_hisWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_hisWeapon = &newWeapon;
}