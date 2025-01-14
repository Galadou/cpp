/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/14 04:29:37 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &cpy);
		Fixed	&operator=(Fixed const &rhs);
		~Fixed();
		
		Fixed(const int comma);
		Fixed(const float nb);

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixedValue;
		static const int	_commaStorage;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);