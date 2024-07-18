# Compiler
CC = cc

# Compiler-Flags
CFLAGS = -Wall -Wextra -std=c11

# Ziel-Datei
TARGET = fdf

# Quellcodedateien
include sources.mk

# Objekt-Dateien
OBJS = $(SRCS:.c=.o)

# Regel für das Ziel
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regel für die Erstellung der Objekt-Dateien
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
