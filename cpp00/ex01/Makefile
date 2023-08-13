# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 21:11:40 by jeekpark          #+#    #+#              #
#    Updated: 2023/08/13 19:17:18 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

CC			= c++
CFALG		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= main.cpp Phonebook.cpp Contact.cpp
OBJS		= ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFALG} ${OBJS} -o ${NAME}

%.o : %.cpp
	${CC} ${CFALG} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re :
	make fclean
	make all

.PHONY = all clean fclean re