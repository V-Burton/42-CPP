/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:40 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 18:58:14 by vburton          ###   ########.fr       */
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

	std::cout << BOLD << UNDERLINE << "Memory address:" << END << std::endl;
	std::cout << BOLD << "\t-str:       " << END << &str << std::endl;
	std::cout << BOLD << "\t-stringPTR: " << END << stringPTR << std::endl;
	std::cout << BOLD << "\t-stringREF: " << END << &stringREF << std::endl;
	std::cout << BOLD << UNDERLINE << "Value:" << END << std::endl;
	std::cout << BOLD << "\t-str:       " << END << str << std::endl;
	std::cout << BOLD << "\t-stringPTR: " << END << *stringPTR << std::endl;
	std::cout << BOLD << "\t-stringREF: " << END << stringREF << std::endl;
	return (0);
}
