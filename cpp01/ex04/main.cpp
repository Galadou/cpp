/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:40:51 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/10 16:05:48 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

//ifstream = mode lecture
//ofstream = ecriture

int	ft_parsing(int argc, char **argv, std::ifstream &infile)
{
	if (argc != 4)
	{
		std::cerr << "Error: bad number of argument" << std::endl;
		return (1);
	}
	if (!*argv[2] || !*argv[3])
	{
		std::cerr << "Error: empty arg" << std::endl;
		return (1);
	}
	if (!infile.is_open())
	{
		std::cerr << "Error: Infile or Outfile error" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv) // doesn't work
{
	std::ifstream infile; 
	std::string myline;
	int i;
	
	infile.open(argv[1]);
	if (ft_parsing(argc, argv, infile))
		return (1);
	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str()); //c_str, permet de convertir un "std::string" en un "const char *"
	if(!outfile.is_open())
	{
		std::cerr << "Error: Infile or Outfile error" << std::endl;
		return (1);
	}
	i = 0;
	while (std::getline(infile, myline))
	{
		if (i > 0)
			outfile << std::endl;
		i++;
		if (myline == argv[2]) // ici je pense
			outfile << argv[3];
		else
			outfile << myline;
	}
	infile.close();
    outfile.close();
	return (0);
}