/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:36 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/10 14:30:00 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &newWeapon) : _name(name), _hisWeapon(newWeapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_hisWeapon.getType() << std::endl;
}