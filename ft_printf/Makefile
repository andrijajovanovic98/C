# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 08:34:29 by ajovanov          #+#    #+#              #
#    Updated: 2024/04/21 08:34:31 by ajovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME        = libftprintf.a
CC          = cc
FLAGS       = -Wall -Werror -Wextra

LIBFT_PATH  = ./libft
LIB_PATH    = ./library
LIBFT       = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIB_PATH)/ft_printf.h
LIBS        = -lftprintf

REMOVE      = rm -f
INCLUDE     = -I $(LIB_PATH) -I $(LIBFT_PATH)

SRCS_PATH   = ./printf
PRINTF_SRCS = $(addprefix $(SRCS_PATH)/,ft_printf.c ft_arg_char.c ft_arg_string.c ft_arg_integer_decimal.c ft_arg_pointer.c ft_arg_unsigned.c ft_arg_hexa_x_X.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

OBJ         = $(PRINTF_OBJS)
AR          = ar rcs

all:        $(NAME)


$(NAME):    $(OBJ)
			@make -C $(LIBFT_PATH)
			@cp $(LIBFT) .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
			 $(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(REMOVE) -rf $(PRINTF_OBJS)
			@make clean -C $(LIBFT_PATH)

fclean:		clean
			@$(REMOVE) $(NAME)
			@$(REMOVE) $(LIBFT_PATH)/libft.a

re:			fclean all

.PHONY:		all clean fclean re

