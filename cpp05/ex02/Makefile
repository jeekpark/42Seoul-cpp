# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 12:43:06 by jeekpark          #+#    #+#              #
#    Updated: 2023/10/27 20:53:59 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run


CXXFLAGS	=	-Wall -Wextra -Werror

SRCS		=	main.cpp					\
				Bureaucrat.cpp AForm.cpp	\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp
OBJS		=	$(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME) : $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@


all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) *_shrubbery

re :
	$(MAKE) fclean
	$(MAKE) all



.PHONY: all clean fclean re