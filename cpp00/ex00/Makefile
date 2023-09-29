# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 20:04:09 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/29 15:50:38 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

CC			= c++
CFALGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= megaphone.cpp
OBJS		= ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFALGS} ${OBJS} -o ${NAME}

%.o : %.cpp
	${CC} ${CFALGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re :
	fclean
	all

.PHONY = all clean fclean re