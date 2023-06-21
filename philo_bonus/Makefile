# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:50:21 by azari             #+#    #+#              #
#    Updated: 2023/06/21 11:45:05 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE 		= 	\033[0;35m

RM 			= 	rm -f

CC 			= 	cc

NAME 		= 	philo_bonus

CFLAGS 		= 	-Wall -Wextra -Werror -pthread -g

HEADER 		=   philo_bonus.h

FILE 		= 	philo_bonus 			\
				srcs/bonus_philo_utils 	\
				srcs/bonus_philo_init 	\
				srcs/bonus_philo_thread 	\
				srcs/bonus_philo_time 	\
				srcs/bonus_philo_act 	\

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