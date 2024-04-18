/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:21:00 by jeekpark          #+#    #+#             */
/*   Updated: 2024/04/18 20:48:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <iostream>
# include <iomanip>

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
		void	show_contacts();
		void	show_contact_by_index(int index);
		int		get_count() const;
};

#endif