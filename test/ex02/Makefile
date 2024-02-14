# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 00:11:52 by jeekpark          #+#    #+#              #
#    Updated: 2023/12/30 09:42:51 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	PmergeMe

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		:=	main.cpp						\
						PmergeMe.cpp

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