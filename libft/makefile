CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar

ARFLAGS = rcs

NAME = libft.a

SRC = 	functions/ft_bzero.c \
functions/ft_isalnum.c \
functions/ft_isalpha.c \
functions/ft_isascii.c \
functions/ft_isdigit.c \
functions/ft_isprint.c \
functions/ft_memchr.c \
functions/ft_memcmp.c \
functions/ft_memcpy.c \
functions/ft_memmove.c \
functions/ft_memset.c \
functions/ft_strchr.c \
functions/ft_strlcat.c \
functions/ft_strlcpy.c \
functions/ft_strlen.c \
functions/ft_strncmp.c \
functions/ft_strrchr.c \
functions/ft_tolower.c \
functions/ft_toupper.c \
functions/ft_strnstr.c \
functions/ft_atoi.c \
functions/ft_calloc.c \
functions/ft_strdup.c \
functions/ft_substr.c \
functions/ft_strjoin.c \
functions/ft_strtrim.c \
functions/ft_split.c \
functions/ft_itoa.c \

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
