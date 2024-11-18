/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:09 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/18 16:59:51 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int main( void ) 
{
	Fixed a;

	a.setRawBits(454);
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}