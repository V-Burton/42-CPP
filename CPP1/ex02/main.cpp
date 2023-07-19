/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:40 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 15:01:54 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define BOLD			"\033[1m"
#define UNDERLINE		"\033[4m"
#define END				"\033[0m"

int main(void){
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << BOLD << "Memory address of the str: " << END << &str << std::endl;
	std::cout << BOLD << "Memory address held by stringPTR: " << END << stringPTR << std::endl;
	std::cout << BOLD << "Memory address held by stringREF: " << END << &stringREF << std::endl;
	std::cout << BOLD << "Value of the string str: " << END << str << std::endl;
	std::cout << BOLD << "Value pointed to by stringPTR: " << END << *stringPTR << std::endl;
	std::cout << BOLD << "Value pointed to by stringREF: " << END << stringREF << std::endl;
	return (0);
}