/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:20:33 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 23:55:57 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void)
{
	setHead((Node *)0);
}

Floor::Floor(const Floor& copy)
{
	clearList();
	setHead(copyList(copy.getHead()));
}

Floor::~Floor(void)
{
	clearList();
}

Floor&	Floor::operator=(const Floor& copy)
{
	clearList();
	setHead(copyList(copy.getHead()));
	return *this;
}

Node*	Floor::getHead(void) const
{
	return _head;
}

void	Floor::setHead(Node* head)
{
	_head = head;
}

void	Floor::addNodeBack(AMateria* content)
{
	if (getHead() == (Node*)0)
		setHead(new Node(content));
	else
	{
		Node* temp = getHead();
		while (temp->getNextNode() != (Node*)0)
			temp = temp->getNextNode();
		temp->setNextNode(new Node(content));
	}
}

void	Floor::clearList(void)
{
	Node* temp = getHead();
	if (temp == (Node*)0)
		return ;
	while (temp != (Node*)0)
	{
		
		delete (AMateria*) temp->getContent();
		temp->setContent((void*)0);
		Node* next = temp->getNextNode();
		delete temp;
		temp = next;
	}
	setHead((Node*)0);
}

Node*	Floor::copyList(Node* head)
{
	Node* temp = head;
	if (temp == (Node*)0)
		return (Node*)0;
	Node* res = new Node(temp->getContent());
	Node* cursor = res;
	while (temp->getNextNode() != (Node*)0)
	{
		cursor->setNextNode(new Node(temp->getNextNode()->getContent()));
		cursor = cursor->getNextNode();
		temp = temp->getNextNode();
	}
	return res;
}
