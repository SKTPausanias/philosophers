# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:25:36 by mlaplana          #+#    #+#              #
#    Updated: 2020/03/06 17:25:37 by mlaplana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = philo_three.c utils.c utils2.c \
	init.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all fclean re
