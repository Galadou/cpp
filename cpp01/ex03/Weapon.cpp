/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:09:20 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/10 15:58:01 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
	return;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor called" << std::endl;
	return;
}

const std::string	&Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
	return;
}
