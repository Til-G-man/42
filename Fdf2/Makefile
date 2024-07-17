CC = cc
CFLAGS = -Wall -Werror -Wextra

include $(sources.mk)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(OBJ).c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
