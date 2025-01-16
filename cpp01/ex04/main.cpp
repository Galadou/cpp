/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:40:51 by gmersch           #+#    #+#             */
/*   Updated: 2025/01/16 14:43:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

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

#include <stdio.h>
void	ft_algo(std::ofstream &outfile, std::ifstream &infile, std::string &myline, char **argv)
{
	size_t pos1;
	std::string full_line;
	std::string replace = argv[2];
	
	while (std::getline(infile, myline))
	{
		full_line = full_line + myline;
		if (!infile.eof())
			full_line = full_line + "\n";
	}
	pos1 = full_line.find(replace);
	while (pos1 != std::string::npos)
	{
		outfile << full_line.substr(0, pos1);
		outfile << argv[3];
		full_line = full_line.substr(pos1 + replace.size());
		pos1 = full_line.find(replace);
	}
	outfile << full_line;
}

int main(int argc, char **argv)
{
	std::ifstream infile; 
	std::string myline;
	
	infile.open(argv[1]);
	if (ft_parsing(argc, argv, infile))
		return (1);
	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
	if(!outfile.is_open())
	{
		std::cerr << "Error: Infile or Outfile error" << std::endl;
		infile.close();
		return (1);
	}
	ft_algo(outfile, infile, myline, argv);
	infile.close();
    outfile.close();
	return (0);
}