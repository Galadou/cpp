/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:14:31 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/14 03:09:23 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl robot;
	std::string level;
	
	level = "INFO";
	robot.complain(level);
	return (0);
}