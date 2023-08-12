CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = do-op

INCLUDES = ./includes
SRCS = ./srcs/

HEADER = do_op.h calculate.h elements.h ft_error.h operation.h
SRC = $(SRCS)do_op.c $(SRCS)calculate.c $(SRCS)elements.c $(SRCS)ft_error.c $(SRCS)operation.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I $(INCLUDES) -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: make clean fclean re all
