/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/18 18:39:08 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Constructeur par défaut
// • Constructeur de copie
// • Opérateur d’affectation
// • Destructeur


class Fixed
{
	public:
		Fixed();//construct
		Fixed(Fixed const &cpy);
		~Fixed();//destruct
		Fixed	&operator=(Fixed const &rhs);

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixedValue;
		static const int	_commaStorage; //static = partager par tout les instances de la class

};