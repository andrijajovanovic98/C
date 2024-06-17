# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 13:31:15 by ajovanov          #+#    #+#              #
#    Updated: 2024/06/15 13:32:27 by ajovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = processes.c utils.c pipex.c ft_split.c error_and_free.c
ODIR = Ofiles
MOBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))
LIB = $(NAME).a

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(MOBJ) pipex.h
	ar rc $(LIB) $(MOBJ)
	$(CC) $(CFLAGS) pipex.c $(LIB) -o $(NAME)

$(ODIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MOBJ)
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
