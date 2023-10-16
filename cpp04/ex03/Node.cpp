/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:07:25 by jeekpark          #+#    #+#             */
/*   Updated: 2023/10/16 17:38:58 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node(void)
{
	setContent(0);
	setNextNode(0);
}

Node::Node(const Node& copy)
{
	setContent(copy.getContent());
	setNextNode(copy.getNextNode());
}

Node::Node(void* content)
{
	setContent(content);
	setNextNode(0);
}

Node::~Node(void)
{

}

Node&	Node::operator=(const Node& copy)
{
	_content = copy.getContent();
	_nextNode = copy.getNextNode();
	return *this;
}

void*	Node::getContent(void) const
{
	return _content;
}

void	Node::setContent(void* content)
{
	_content = content;
}

Node*	Node::getNextNode(void) const
{
	return _nextNode;
}

void	Node::setNextNode(Node* nextNode)
{
	_nextNode = nextNode;
}

void	Node::deleteContent(void)
{
	delete _content;
}