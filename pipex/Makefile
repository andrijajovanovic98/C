NAME = pipex
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = free.c pipex.c ft_split.c utils.c
ODIR = Ofiles
MOBJ = $(SRC:%.c=$(ODIR)/%.o)

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(MOBJ)
	$(CC) $(CFLAGS) $(MOBJ) -o $(NAME)

$(ODIR)/%.o: %.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MOBJ)
	$(RM) -rf $(ODIR)

fclean: clean
	$(RM) $(NAME)
	rm -rf $(ODIR)

re: fclean all

.PHONY: all clean fclean re

