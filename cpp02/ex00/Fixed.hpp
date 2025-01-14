/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:16:14 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/14 03:44:42 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &cpy);
		~Fixed();
		Fixed	&operator=(Fixed const &rhs);

		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixedValue;
		static const int	_commaStorage;
};