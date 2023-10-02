# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 16:13:08 by jeekpark          #+#    #+#              #
#    Updated: 2023/10/02 17:17:48 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harlFilter

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp		\
				Harl.cpp
OBJS		= $(SRCS:.cpp=.o)

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

.PHONY: all clean fclean re