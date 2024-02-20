/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:49:36 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/19 13:32:34 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* public head */
RPN::RPN(void) {}

RPN::RPN(const RPN& copy) : mStack(copy.mStack) {}

RPN::~RPN(void) {}

RPN& RPN::operator=(const RPN& copy)
{
  if (this != &copy) mStack = copy.mStack;
  return *this;
}

void RPN::clear(void)
{
  mStack = std::stack<double>();
}

void RPN::insert(char c)
{
  if (std::isdigit(static_cast<int>(c)))
  {
    push(c - '0');
    return;
  }
  if (size() < 2)
    throw RPN::IncompleteExpressionException();
  double a, b;
  switch (c)
  {
  case '+':
    a = top(); pop();
    b = top(); pop();
    push(b + a);
    break;
  case '-':
    a = top(); pop();
    b = top(); pop();
    push(b - a);
    break;
  case '*':
    a = top(); pop();
    b = top(); pop();
    push(b * a);
    break;
  case '/':
    a = top(); pop();
    b = top(); pop();
    push(b / a);
    break;
  default:
    throw RPN::IncompleteExpressionException();
  }
}

double RPN::result(void) const
{
  if (size() == 1) return top();
  else throw RPN::IncompleteExpressionException();
}

const char* RPN::IncompleteExpressionException::what(void) const throw()
{
  return "Incomplete Expression";
}
/* public tail */




/* private head */
void RPN::push(double n)
{
  mStack.push(n);
}

void RPN::pop(void)
{
  mStack.pop();
}

double RPN::top(void) const
{
  return mStack.top();
}

size_t RPN::size(void) const
{
  return mStack.size();
}
/* private tail */