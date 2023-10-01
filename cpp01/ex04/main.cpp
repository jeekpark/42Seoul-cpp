/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:03:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/01 15:50:55 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string replaceString(std::string subject, const std::string& search, const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

int	main ( int argc, char **argv )
{
	if ( argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>." << std::endl;
		return 1; 
	}
	std::ifstream	file(argv[1]);
	if ( file.is_open() == false )
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		return 1;
	}

	std::ostringstream	ss;
	ss << file.rdbuf();
	std::string content = ss.str();

	content = replaceString(content, argv[2], argv[3]);

	file.close();
	std::ofstream	outFile("heloo");
	outFile << content;
	outFile.close();
	return (0);
}