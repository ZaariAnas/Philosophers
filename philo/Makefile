# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 12:40:48 by azari             #+#    #+#              #
#    Updated: 2023/06/17 14:49:30 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE 		= 	\033[0;35m

RM 			= 	rm -f

CC 			= 	cc

NAME 		= 	philosphers

CFLAGS 		= 	-Wall -Wextra -Werror -pthread -g -fsanitize=address

HEADER 		=   philo.h

FILE 		= 	philo 				\
				srcs/philo_utils 	\
				srcs/philo_init 	\
				srcs/philo_time 	\

SRCS 		= 	$(addsuffix .c, $(FILE))
OBJS 		= 	$(addsuffix .o, $(FILE))

%.o : %.c $(HEADER) 
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $^
	@echo "$(PURPLE) ✅ Philosophers "

clean:
	@$(RM) $(OBJS)
	@echo  "$(PURPLE) ❌ OBJS deleted."

fclean: clean 
	@$(RM) $(NAME)
	@echo  "$(PURPLE) ❌ ALL deleted."


re: fclean all 

cl : all clean

.PHONY: clean fclean re all