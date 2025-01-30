#------------------ Srcs & Objs -------------------#
SERVER_SRC = server.c
CLIENT_SRC = client.c
#SERVER_OBJS = $(SERVER_SRC:.c=.o)
#CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

#------------------ LIBFT ------------------#
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#----------------- Constant namings ---------------------#
CC = cc
RM = rm -f
#don't forget to put those back here
#CFLAGS = -Wall -Werror -Wextra

SERVER_NAME = server
CLIENT_NAME = client

#--------------------- RULES --------------------#

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
		@cd libft && make

$(SERVER_NAME): $(SERVER_SRC)
		$(CC) $(CFLAGS) $< $(LIBFT) -o $@

$(CLIENT_NAME): $(CLIENT_SRC)
		$(CC) $(CFLAGS) $< $(LIBFT) -o $@

clean:
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		@cd $(LIBFT_DIR) && make clean

fclean: clean
		@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re