# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:41:33 by tilman            #+#    #+#              #
#    Updated: 2024/07/18 17:59:39 by tgluckli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler-Flags
CFLAGS = -Wall -Wextra -std=c11 -fPIE

# Linker-Flags
LDFLAGS = -fPIE

# Ziel-Datei
TARGET = fdf

# Quellcodedateien
include sources.mk

# Objekt-Dateien
OBJS = $(SRCS:.c=.o)

# Regel für das Ziel
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

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

