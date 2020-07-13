# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 15:34:19 by mlaplana          #+#    #+#              #
#    Updated: 2020/03/06 16:28:17 by mlaplana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = philo_one.c utils.c init.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all fclean re
