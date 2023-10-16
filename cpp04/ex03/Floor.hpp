/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:00:11 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 21:34:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "Node.hpp"
# include "AMateria.hpp"

class Floor
{
	private:
		Node*	_head;
	public:
				Floor(void);
				Floor(const Floor& copy);
				~Floor(void);
		Floor&	operator=(const Floor& copy);

		Node*	getHead(void) const;
		void	setHead(Node* head);
		void	addNodeBack(AMateria* content);
		void	clearList(void);
		Node*	copyList(Node *head);
};

#endif