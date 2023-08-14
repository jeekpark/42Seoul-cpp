# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 11:49:08 by jeekpark          #+#    #+#              #
#    Updated: 2023/08/14 11:55:53 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= account

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= Account.cpp tests.cpp
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re