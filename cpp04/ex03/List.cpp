/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:20:33 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:41:46 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

List::List(void)
{
	setHead((Node *)0);
}

List::List(const List& copy)
{
	setHead(copy.getHead());
}

List::~List(void)
{
	clearList();
}

List&	List::operator=(const List& copy)
{
	setHead(copy.getHead());
	return *this;
}

Node*	List::getHead(void) const
{
	return _head;
}

void	List::setHead(Node* head)
{
	_head = head;
}
#include <stdio.h>
void	List::addNodeBack(void *content)
{
	if (getHead() == 0)
	{
		setHead(new Node(content));
		return ;
	}
	else
	{
		Node* temp = getHead();
		while (temp->getNextNode() == 0)
			temp = temp->getNextNode();
		
		temp->setNextNode(new Node(content));
		
	}
}

void	List::clearList(void)
{
	Node* temp = getHead();
	while (temp != 0)
	{
		
		temp->deleteContent();
		Node* next = temp->getNextNode();
		delete temp;
		temp = next;
	}
}
