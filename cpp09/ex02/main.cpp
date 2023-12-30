/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:14:14 by jeekpark          #+#    #+#             */
/*   Updated: 2023/12/30 09:41:17 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "PmergeMe.hpp"


int main(const int argc, const char** argv)
{
  PmergeMe pm(argc, argv);
  
  return pm.sort() ? 0 : 1;
}