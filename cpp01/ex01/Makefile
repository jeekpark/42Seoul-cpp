# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 15:58:23 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/30 16:20:52 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	Zombie.cpp				\
				main.cpp				\
				ZombieHorde.cpp			

OBJS		=	${SRCS:.cpp=.o}

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean :
	${RM} ${OBJS} ${NAME}

re :
	make fclean
	make all

.PHONY: all clean fclean re