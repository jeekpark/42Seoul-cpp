/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:17:06 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/06 16:55:09 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

static void	_something(int num)
{
	std::cout << num << std::endl;
}

int main(void)
{
	int arr[3] = {1, 2, 3};
	iter(arr, 3, _something);
	return 0;
}