/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:33 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/08 17:50:34 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		while (argv[i][j])
		{
			std::cout << (char)(toupper(argv[i][j]));
			j++;
		}
	}
	std::cout << std::endl;
	return 0;
}