/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:33:40 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/15 21:18:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"
int main(void)
{
	Ice* a = new Ice();


	Ice* b;

	b = a;

	Character c("jeekun");
	b->use(c);
}