/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:01 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/15 17:42:11 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 10;
	Zombie *horde;
	
	horde = zombieHorde(N, "Tom");
	delete[] horde;
	return (0);
}