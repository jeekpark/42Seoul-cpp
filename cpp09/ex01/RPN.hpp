/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:23:49 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:33:29 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>


class RPN
{
public:
                      RPN(void);
                      RPN(const RPN& copy);
                      ~RPN(void);
  RPN&                operator=(const RPN& copy);

  void                clear(void);
  void                insert(char c);
  double              result(void) const;

  class IncompleteExpressionException : public std::exception
  { public: virtual const char* what(void) const throw(); };
private:
  std::stack<double>  mStack;
   
  void                push(double n);
  void                pop(void);
  double              top(void) const;
  size_t              size(void) const;
};

#endif