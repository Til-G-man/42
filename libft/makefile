CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar

ARFLAGS = rcs

NAME = libft.a

SRC = functions/ft_isalpha.c \
      functions/ft_isdigit.c \
      functions/ft_isalnum.c \
      functions/ft_isascii.c \
      functions/ft_isprint.c \
      functions/ft_strlen.c \
      functions/ft_memset.c \
      functions/ft_bzero.c \
      functions/ft_memcpy.c \
      functions/ft_memmove.c \
      functions/ft_strlcat.c \
      functions/ft_strlcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	cp libft.h includes/
	rm -f $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
