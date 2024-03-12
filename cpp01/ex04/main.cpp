/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:03:38 by jeekpark          #+#    #+#             */
/*   Updated: 2024/03/12 16:27:49 by jeekpark         ###   ########.fr       */
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
		return 1; 
	}
	if ( std::string(argv[2]).empty() == true )
	{
		std::cerr << "Error: <s1> shouldn't be empty string." << std::endl;
		return 1;
	}
	std::ifstream	file( argv[1], std::ios::in | std::ios::out );
	if ( file.is_open() == false )
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		return 1;
	}
	std::ostringstream	stringStream;
	stringStream << file.rdbuf();
	file.close();
	std::string content = stringStream.str();

	content = replaceString( content, argv[2], argv[3] );

	std::string	newFileName( argv[1] );
	newFileName.append( ".replace" );
	std::ofstream	outFile( newFileName.c_str() );
	if (!outFile)
	{
		std::cerr << "Error: Unable to open or create file." << std::endl;
		return 1;
	}
	outFile << content;
	if (outFile.fail())
	{
		std::cerr << "Error: Failed to write to the file '" << newFileName << "'." << std::endl;
		outFile.close();
		return 1;
	}
	outFile.close();
	return 0;
}