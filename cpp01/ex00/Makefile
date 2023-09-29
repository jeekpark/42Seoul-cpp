# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 00:26:32 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/30 01:23:25 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	run

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp			\
			Zombie.cpp			\
			randomChump.cpp		\
			newZombie.cpp

OBJS	=	${SRCS:.cpp=.o}

%.o : %.cpp
	${CC} ${CFALGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re