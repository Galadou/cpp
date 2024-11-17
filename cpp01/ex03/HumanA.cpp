/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:36 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:24:54 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//constructor
HumanA::HumanA(std::string name, Weapon &newWeapon) : _name(name), _hisWeapon(newWeapon)
{
	return;
}

//destructor
HumanA::~HumanA(void)
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_hisWeapon.getType() << std::endl;
}