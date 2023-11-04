/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:57:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/04 17:06:07 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <_ctype.h>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main()
{
	char *endptr = NULL;
	char *s = strdup("inf");
	double a = std::strtod(s, &endptr);
	printf("%lf %d\n", a, *endptr);
	free(s);
}