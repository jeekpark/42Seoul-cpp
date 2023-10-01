# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 14:59:44 by jeekpark          #+#    #+#              #
#    Updated: 2023/10/01 15:06:03 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	replace

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