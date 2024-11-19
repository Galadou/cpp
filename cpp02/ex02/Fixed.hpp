/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/19 21:17:01 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cmath>

// Constructeur par défaut
// • Constructeur de copie
// • Opérateur d’affectation
// • Destructeur


class Fixed
{
	//CONST DANS TOUT CA ???
	public:
	//de base:
		Fixed();//construct base
		Fixed(Fixed const &cpy);
		Fixed	&operator=(Fixed const &src);
		~Fixed();//destruct
		
		int		operator>(Fixed const &src) const;
		int		operator<(Fixed const &src) const;
		int		operator>=(Fixed const &src) const;
		int		operator<=(Fixed const &src) const;
		int		operator==(Fixed const &src) const;
		int		operator!=(Fixed const &src) const;

		Fixed	operator+(Fixed const &src) const;
		Fixed	operator-(Fixed const &src) const;
		Fixed	operator*(Fixed const &src) const;
		Fixed	operator/(Fixed const &src) const;

		Fixed &operator++(); // Pré-incrémentation
		Fixed &operator--(); // Pré-décrémentation
		Fixed operator++(int); // Post-incrémentation
		Fixed operator--(int); // Post-décrémentation

		static Fixed	&min(Fixed &nb1, Fixed &nb2);
		const static Fixed	&min(Fixed const &nb1, Fixed const &nb2);
		static Fixed	&max(Fixed &nb1, Fixed &nb2);
		const static Fixed	&max(Fixed const &nb1, Fixed const &nb2);

		Fixed(const int comma);//construct int
		Fixed(const float nb);//construct float

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixedValue;
		static const int	_commaStorage; //static = partager par tout les instances de la class
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);