/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:23:16 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:25:16 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &newWeapon);
		~HumanA();
		
		void	attack();
	
	private:
		std::string _name;
		Weapon 		&_hisWeapon;	
};

#endif