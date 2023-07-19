/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:06:54 by vburton           #+#    #+#             */
/*   Updated: 2023/07/19 19:36:43 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

using std::string;

int	replace(string filename, string s1, string s2)
{
	s1 =s2;
	std::string newFilePath = filename + ".replace";
	std::ofstream newFile(newFilePath.c_str());
	std::fstream originalFile;
	std::fstream newF;
	newF.open(newFile, std::ios::in);
	originalFile.open(filename,std::ios::out);

	return (0);
}

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Proper use of replace is './replace <filename> <s1> <s2>'" << std::endl;
		return(1);
	}
	replace(argv[1], argv[2], argv[3]);
	return (0);
}
