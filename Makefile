CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

FILES = ft_printf.c	helper_functions.c	helper_functions_2.c

OBJECTS = $(FILES:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
