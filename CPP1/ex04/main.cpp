/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburton <vburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:06:54 by vburton           #+#    #+#             */
/*   Updated: 2023/07/20 15:00:47 by vburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	replace(const std::string filename, std::string s1, std::string s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Error oppening the input file" << std::endl;
		return (1);		
	}
	const std::string newFilePath = filename + ".replace";
	std::ofstream newFile(newFilePath.c_str(), std::ios::trunc);
	if (!newFile.is_open()){
		std::cerr << "Error oppening the new file" << std::endl;
		inputFile.close();
		return (1);		
	}
	std::string line;
	std::string newLine;
	while (std::getline(inputFile, newLine)){
		size_t pos = 0;
		while((pos = newLine.find(s1, pos)) != std::string::npos && s1.size() > 0){
			newLine.erase(pos, s1.size());
			newLine.insert(pos, s2);
			pos += s2.size();
		}
		newFile << newLine << "\n";
	}
	inputFile.close();
	newFile.close();
	return (0);
}

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Proper use of \"./replace\" is \"./replace <filename> <s1> <s2>\"" << std::endl;
		return(1);
	}
	replace(argv[1], argv[2], argv[3]);
	return (0);
}
