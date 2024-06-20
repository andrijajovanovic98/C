NAME = pipex
CC = cc -g
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