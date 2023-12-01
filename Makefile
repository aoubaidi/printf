SRC = ft_printf.c help_fts.c print_fts.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $?
%.o : %.c
	$(CC) $(CFLAGS) $< -c
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
