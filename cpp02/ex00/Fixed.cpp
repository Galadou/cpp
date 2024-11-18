/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/18 18:39:08 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

		//EXPLICATION POUR BIEN COMPRENDRE
// Si on te dit que le nombre de bits pour la partie fractionnaire est de 8, (comme ici)
// cela signifie que tous les 8 bits de droite dans
// ton entier sont utilisés pour représenter la partie fractionnaire, (le après-virgule)
// et les autres bits (généralement à gauche) représentent la partie entière.
//On divise le resultat des bits (par exemple 128) par 256, car si 255 est la valeur max,
//on veux savoir combien de "pourcent" on a de 256. Par exemple, le max (255) / 256 
//donne la valeur la plus precise et la plus proche de "l'avant 1" pour 8 bit, comme dans notre cas.
// Avec 8 bits pour la fraction, tu as seulement 256 valeurs possibles pour la partie fractionnaire, 
// ce qui correspond à une précision de 1/256. Mais si tu veux une précision plus fine
// (plus de chiffres après la virgule), il te faudra plus de bits pour la partie fractionnaire.
const int Fixed::_commaStorage = 8;

//En général, les divisions sur des int ne sont pas très précis.
//La méthode faite dans cet exercice est encore très utilisé
//aujourd'hui, car très pratique !

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

//copy tout les elements de ma class
Fixed::Fixed(Fixed const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedValue = cpy._fixedValue;
}

Fixed	&Fixed::operator=(const Fixed &rhs) //& car on veux pas duplliquer
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) //si diff
	{
		this->_fixedValue = rhs.getRawBits();
	}
	return *this; //on renvoie ce quil contient
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