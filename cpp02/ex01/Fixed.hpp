/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/18 20:07:46 by gmersch          ###   ########.fr       */
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
	public:
	//de base:
		Fixed();//construct base
		Fixed(Fixed const &cpy);
		Fixed	&operator=(Fixed const &rhs);
		~Fixed();//destruct
		
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