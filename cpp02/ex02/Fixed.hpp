/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/17 14:10:16 by gmersch          ###   ########.fr       */
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
		Fixed	&operator=(Fixed const &src);
		~Fixed();
		
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

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed	&min(Fixed &nb1, Fixed &nb2);
		const static Fixed	&min(Fixed const &nb1, Fixed const &nb2);
		static Fixed	&max(Fixed &nb1, Fixed &nb2);
		const static Fixed	&max(Fixed const &nb1, Fixed const &nb2);

		Fixed(const int comma);
		Fixed(const float nb);

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_fixedValue;
		static const int	_commaStorage = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);