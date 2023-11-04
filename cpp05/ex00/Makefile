# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:43:06 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/04 12:41:20 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run


CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Bureaucrat.cpp
OBJS		=	$(SRCS:.cpp=.o)





all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

.PHONY: all clean fclean re