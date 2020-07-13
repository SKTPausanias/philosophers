# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 16:47:30 by mlaplana          #+#    #+#              #
#    Updated: 2020/03/06 16:47:32 by mlaplana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = philo_two.c utils.c utils2.c \
	init.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all fclean re
