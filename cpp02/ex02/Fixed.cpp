/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/19 21:31:45 by gmersch          ###   ########.fr       */
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

Fixed	&Fixed::operator=(const Fixed &src) //& car on veux pas duplliquer
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) //si diff
	{
		this->_fixedValue = src._fixedValue;
	}
	return *this; //on renvoie ce quil contient
}

int	Fixed::operator>(Fixed const &src) const
{
	return (this->toFloat() > src.toFloat());
}


int	Fixed::operator<(Fixed const &src) const
{
	return (this->toFloat() < src.toFloat());
}
		
int	Fixed::operator<=(Fixed const &src) const
{
	return (this->toFloat() <= src.toFloat());
}

int	Fixed::operator>=(Fixed const &src) const
{
	return (this->toFloat() >= src.toFloat());
}

int	Fixed::operator==(Fixed const &src) const
{
	return (this->toFloat() == src.toFloat());
}

int	Fixed::operator!=(Fixed const &src) const
{
	return (this->toFloat() != src.toFloat());
}

Fixed	Fixed::operator+(Fixed const &src) const
{
	return(Fixed(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &src) const
{
	return(Fixed(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &src) const
{
	return(Fixed(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &src) const
{
	return(Fixed(this->toFloat() / src.toFloat()));
}

Fixed	Fixed::operator++(int) //	x++
{
	Fixed	tmp(*this); //on garde lancienne valeur de coté
	this->_fixedValue++; //on incremente celle ci
	return(tmp); //on return l'ancien
}

Fixed	Fixed::operator--(int) //	x--
{
	Fixed	tmp(*this); //on garde lancienne valeur de coté
	this->_fixedValue--; //on incremente celle ci
	return(tmp); //on return l'ancien
}

Fixed	&Fixed::operator++() //	++x
{
	this->_fixedValue++; 
	return(*this); //on return *this avec une * car on veux recuperer le contenu :
	//sinon on ne peux pas faire "b = a++" car a++ ferais juste une action
	//sur l'instance 'a' mais ne serais 'rien' en soi. Donc a++; doit renvoyer
	//la valeur de 'a' et non pas l'adress de 'a'. On veux comparer 'b' avec
	//une instance ('a' dans notre cas), et non pas une adresse d'instance
	//(si on avais juste fais 'this' au lieu de '*this').
}

Fixed	&Fixed::operator--() //	--x
{
	this->_fixedValue--; 
	return(*this);
}

Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

const Fixed	&Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed	&Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
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