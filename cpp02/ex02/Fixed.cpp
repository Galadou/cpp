/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:18 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/17 14:28:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = nb * (1 << Fixed::_commaStorage);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(nb * (1 << Fixed::_commaStorage));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedValue = src._fixedValue;
	return (*this);
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

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++this->_fixedValue;
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--this->_fixedValue;
	return(tmp);
}

Fixed	&Fixed::operator++()
{
	++this->_fixedValue; 
	return(*this);
}

Fixed	&Fixed::operator--()
{
	--this->_fixedValue; 
	return(*this);
}

Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

const Fixed	&Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

const Fixed	&Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedValue / (1 << Fixed::_commaStorage));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedValue / (1 << Fixed::_commaStorage));
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