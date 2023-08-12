CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
INCLUDES = ./includes
SRCS = ./srcs/
HEADER = bsq.h solve.h allocation.h dp.h init_map.h t_map_ele.h
SRC = $(SRCS)bsq.c $(SRCS)solve.c $(SRCS)allocation.c $(SRCS)dp.c $(SRCS)init_map.c
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
