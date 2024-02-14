/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDateFormat.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:40:11 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:34 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ISDATEFORMAT_HPP
#define ISDATEFORMAT_HPP

#include <string>

bool  isLeapYear(long year);
bool  isDateFormat(const std::string& str);

#endif