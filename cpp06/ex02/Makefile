# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 00:11:52 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/06 15:59:36 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	run

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	main.cpp			

OBJS		:=	$(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re