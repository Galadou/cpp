/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/18 20:16:39 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//explication à ex00
const int Fixed::_commaStorage = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = nb * 256;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(nb * 256); //arrondi a lentier de virgule le plus proche (si 1.1458) ca fais 1.146 PAR EXEMPLE
	//this->_fixedValue = nb * 256; pas assez precis
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//copy tout les elements de ma class
Fixed::Fixed(Fixed const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &rhs) //& car on veux pas duplliquer
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) //si diff
	{
		this->_fixedValue = rhs._fixedValue;
	}
	return *this; //on renvoie ce quil contient
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedValue / 256.0);
}

int Fixed::toInt( void ) const
{
	return (this->_fixedValue / 256);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedValue = raw;
}
std::ostream	&operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}