# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tilman <tilman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:41:33 by tilman            #+#    #+#              #
#    Updated: 2024/08/23 16:00:59 by tilman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler-Flags
CFLAGS = -Wall -Wextra -std=c11 -fPIE

MLX_PATH = ./minilibx-linux

# Linker-Flags
LDFLAGS = -fPIE -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# Ziel-Datei
TARGET = fdf

# Quellcodedateien
include sources.mk

# Objekt-Dateien
OBJS = $(SRCS:.c=.o)

# Regel für das Ziel
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Regel für die Erstellung der Objekt-Dateien
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

.PHONY: all clean fclean re

