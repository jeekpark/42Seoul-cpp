# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 00:26:32 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/30 15:58:06 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	run

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp			\
			Zombie.cpp			\
			randomChump.cpp		\
			newZombie.cpp

OBJS	=	${SRCS:.cpp=.o}

%.o : %.cpp
	${CXX} ${CXXFALGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re