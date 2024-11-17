/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:58 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:23:59 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "constructor called for a Zombie" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "destructor called for " << this->_name << std::endl;
	return;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}



