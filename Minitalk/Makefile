#------------------ Srcs & Objs -------------------#
SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_OBJS = $(SERVER_SRC:.c=.o)

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

#------------------ LIBFT ------------------#

LIBFT = cd libft && make

LIB = libft/libft.a

#----------------- Constant namings ---------------------#

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS		= 

SERVER_NAME = server

CLIENT_NAME = client

#--------------------- RULES --------------------#

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME):	libft server client

libft: $(LIBFT)

server: $(SERVER_OBJS)
		$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)

client: $(CLIENT_OBJS)
		$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)

clean:
		${RM} $(CLIENT_OBJS) $(SERVER_OBJS)
		cd libft && make clean

fclean: clean
		${RM} $(SERVER_NAME) $(CLIENT_NAME)
		cd libft && make fclean

re: 	fclean all

.PHONY: all server client libft clean fclean re