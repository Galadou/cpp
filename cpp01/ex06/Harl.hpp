/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:27:22 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:27:23 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();

		void complain( std::string level );

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif