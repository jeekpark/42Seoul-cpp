/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:41:13 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/14 22:03:21 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string			_ideas[100];
	public:
							Brain(void);
							Brain(const Brain& brain);
		Brain&				operator=(const Brain& brain);
							~Brain(void);

		void				setIdeaByIndex(const std::string& idea, int index);
		const std::string&	getIdeaByIndex(int index) const;
};

#endif /* BRAIN_HPP */