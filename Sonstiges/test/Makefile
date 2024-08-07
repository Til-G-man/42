CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = array.a

SRC = libft_printf/libft/ft_bzero.c \
libft_printf/libft/ft_isalnum.c \
libft_printf/libft/ft_isalpha.c \
libft_printf/libft/ft_isascii.c \
libft_printf/libft/ft_isdigit.c \
libft_printf/libft/ft_isprint.c \
libft_printf/libft/ft_memchr.c \
libft_printf/libft/ft_memcmp.c \
libft_printf/libft/ft_memcpy.c \
libft_printf/libft/ft_memmove.c \
libft_printf/libft/ft_memset.c \
libft_printf/libft/ft_strchr.c \
libft_printf/libft/ft_strlcat.c \
libft_printf/libft/ft_strlcpy.c \
libft_printf/libft/ft_strlen.c \
libft_printf/libft/ft_strncmp.c \
libft_printf/libft/ft_strrchr.c \
libft_printf/libft/ft_tolower.c \
libft_printf/libft/ft_toupper.c \
libft_printf/libft/ft_strnstr.c \
libft_printf/libft/ft_atoi.c \
libft_printf/libft/ft_calloc.c \
libft_printf/libft/ft_strdup.c \
libft_printf/libft/ft_substr.c \
libft_printf/libft/ft_strjoin.c \
libft_printf/libft/ft_strtrim.c \
libft_printf/libft/ft_split.c \
libft_printf/libft/ft_itoa.c \
libft_printf/libft/ft_strmapi.c \
libft_printf/libft/ft_striteri.c \
libft_printf/libft/ft_putchar_fd.c \
libft_printf/libft/ft_putstr_fd.c \
libft_printf/libft/ft_putendl_fd.c \
libft_printf/libft/ft_putnbr_fd.c \
libft_printf/ft_putptr.c \
libft_printf/ft_intohex.c \
libft_printf/ft_printf.c \
libft_printf/ft_putunbr_fd.c \
main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
