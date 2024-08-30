NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRC = main.c check_args.c check_args_utils.c init_and_join.c time.c activities_separately.c monitoring.c utils.c
ODIR = Ofiles
MOBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))

all: $(ODIR) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(MOBJ)
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
