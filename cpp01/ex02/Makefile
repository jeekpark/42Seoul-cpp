# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 17:50:44 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/30 17:54:01 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY: all fclean clean re