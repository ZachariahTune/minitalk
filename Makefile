S_SRCS	=	server.c utils.c
S_OBJS	=	$(S_SRCS:.c=.o)

C_SRCS	=	client.c utils.c
C_OBJS	=	$(C_SRCS:.c=.o)

BS_SRCS	=	server_bonus.c utils.c
BS_OBJS	=	$(BS_SRCS:.c=.o)

BC_SRCS	=	client_bonus.c utils.c
BC_OBJS	=	$(BC_SRCS:.c=.o)

CC		=	gcc
RM 		= 	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.
S_NAME	=	server
C_NAME	=	client

all: 		$(S_NAME) $(C_NAME)

$(S_NAME):	$(S_OBJS)
			$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJS)

$(C_NAME):	$(C_OBJS)
			$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJS)

bonus:		$(BS_OBJS) $(BC_OBJS)
			$(CC) $(CFLAGS) -o $(S_NAME) $(BS_OBJS)
			$(CC) $(CFLAGS) -o $(C_NAME) $(BC_OBJS)

clean:
			$(RM) $(S_OBJS) $(C_OBJS) $(BS_OBJS) $(BC_OBJS)

fclean:		clean
			$(RM) $(S_NAME)
			$(RM) $(C_NAME)

re:			fclean all

.PHONY:		all $(S_NAME) $(C_NAME) bonus clean fclean re
