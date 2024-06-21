# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 10:25:10 by ajovanov          #+#    #+#              #
#    Updated: 2024/06/21 10:25:13 by ajovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = processes.c utils.c pipex.c ft_split.c error_and_free.c
ODIR = Ofiles
MOBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(MOBJ) pipex.h
	$(CC) $(CFLAGS) $(MOBJ) -o $(NAME)

$(ODIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MOBJ)
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
