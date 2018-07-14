CC 	= gcc
NAME 	= server.out
LDFLAGS = -lzmq
SRC	= src/c/server/server.c
OBJS 	= $(SRC:%.c=%.o)
RM	= rm -f

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS)

clean: $(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean

re: fclean all

%.o:%.c
	$(CC) -c -o $@ $<

