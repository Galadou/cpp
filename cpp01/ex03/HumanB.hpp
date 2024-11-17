/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:23:13 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:25:43 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &newWeapon);
		
	private:
		std::string	_name;
		Weapon 		*_hisWeapon;

};

#endif