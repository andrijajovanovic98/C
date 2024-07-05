# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 12:22:50 by ajovanov          #+#    #+#              #
#    Updated: 2024/06/28 12:23:00 by ajovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

MLXFLAGS = -lmlx -lXext -lX11 -lm

SRCS = srcs/main.c srcs/map.c srcs/draw.c srcs/close_window.c srcs/load_images.c srcs/free_function.c srcs/heightwidth.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/checks.c srcs/checkstwo.c srcs/checksthree.c srcs/utils.c srcs/utilstwo.c

HDRS = includes/game.h includes/get_next_line.h

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAGS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

