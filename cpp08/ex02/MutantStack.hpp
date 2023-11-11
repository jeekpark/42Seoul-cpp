/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:50:44 by jeekpark          #+#    #+#             */
/*   Updated: 2023/11/11 19:50:51 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename Type, typename Container = std::deque<Type> >
class MutantStack : public std::stack<Type, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	
	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
	const_iterator begin(void) const { return this->c.begin(); }
	const_iterator end(void) const { return this->c.end(); }	
};

#endif
