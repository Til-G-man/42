CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC =	testcode.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strlcat.c

OBJ = $(SRC:.c=.o)

NAME = libft

all: $(NAME) clean

$(NAME):: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(OBJ)

re: fclean all
.PHONY: all clean fclean re
