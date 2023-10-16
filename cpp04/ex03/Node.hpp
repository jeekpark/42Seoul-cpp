/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:02:55 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:38:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef NODE_HPP
# define NODE_HPP

class Node
{
	private:
		void*	_content;
		Node*	_nextNode;
	public:
				Node(void);
				Node(const Node& copy);
				Node(void* content);
				~Node(void);
		Node&	operator=(const Node& copy);

		void*	getContent(void) const;
		void	setContent(void* content);
		Node*	getNextNode(void) const;
		void	setNextNode(Node* nextNode);
		void	deleteContent(void);
};

#endif