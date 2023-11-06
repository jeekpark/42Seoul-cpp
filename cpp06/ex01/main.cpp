/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:57:43 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 14:12:12 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

#include "Serializer.hpp"

int main(int argc, char **argv)
{
	{
		Data *myData = new Data;
		myData->data = 55;
		std::uintptr_t ptr = Serializer::serialize(myData);
		Data *myDataCopy = Serializer::deserialize(ptr);
		std::cout << "myData:\t\t" << myData->data << std::endl;
		std::cout << "myDataCopy:\t" << myDataCopy->data << std::endl;
		myDataCopy->data = 20;
		std::cout << "myData:\t\t" << myData->data << std::endl;
		std::cout << "myDataCopy:\t" << myDataCopy->data << std::endl;
		delete myData;
	}
	return 0;
}