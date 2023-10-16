/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:00:11 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:34:13 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"

class List
{
	private:
		Node*	_head;
	public:
				List(void);
				List(const List& copy);
				~List(void);
		List&	operator=(const List& copy);

		Node*	getHead(void) const;
		void	setHead(Node *head);
		void	addNodeBack(void *content);
		void	clearList(void);
};

#endif