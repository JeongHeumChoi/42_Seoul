CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = ./includes
HEADER = ft.h

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(NAME): $(OBJS) $(INCLUDE)/$(HEADER)
	ar -rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : make clean fclean re all
