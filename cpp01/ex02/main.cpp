/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:24:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/11/17 18:24:30 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "adress of str: " << &str << std::endl;
	std::cout << "adress held by PTR: " << stringPTR << std::endl;
	std::cout << "adress held by REF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "str: " << str << std::endl;
	std::cout << "PTR: " << *stringPTR << std::endl;
	std::cout << "str: " << stringREF << std::endl;

}