/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:03:38 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/02 15:28:36 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string replaceString( std::string content, const std::string& search, const std::string& replace )
{
	size_t	pos = 0;
	while ( true )
	{
		pos = content.find( search, pos );
		if ( pos == std::string::npos )
			break;
		content = content.substr( 0, pos ) + replace + content.substr( pos + search.length() );
		pos += replace.length();
	}
	return content;
}

int	main( int argc, char **argv )
{
	if ( argc != 4 )
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>." << std::endl;
		return EXIT_FAILURE; 
	}
	if ( std::string(argv[2]).empty() == true )
	{
		std::cerr << "Error: <s1> shouldn't be empty string." << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream	file( argv[1], std::ios::in | std::ios::out );
	if ( file.is_open() == false )
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::ostringstream	stringStream;
	stringStream << file.rdbuf();
	file.close();
	std::string content = stringStream.str();

	content = replaceString( content, argv[2], argv[3] );

	std::ofstream	outFile( std::string( argv[1] ) + ".replace" );
	outFile << content;
	outFile.close();

	return EXIT_SUCCESS;
}