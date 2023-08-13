/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:21:00 by jeekpark          #+#    #+#             */
/*   Updated: 2023/08/13 19:16:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_count;
		void	_print_value(std::string str);
		void	_print_contact(int index);
	public:
		Phonebook();
		~Phonebook();

		void	add();
		void	search();
};

#endif