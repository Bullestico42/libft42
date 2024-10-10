# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:29:27 by apiscopo          #+#    #+#              #
#    Updated: 2024/10/01 16:29:27 by apiscopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AR = ar rcs
#Règle par défaut
all: $(NAME)

#Règle par défaut
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

#Compilation des fichier .o a partir des .c
%.o: &.c
	$(CC) $(CFLAGS) -c $< -o $@

#Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

#Nettoyage des fichiers objets et de la bibliothèque
fclean: clean
	rm -f $(NAME)

#Rebuild complet
re: fclean all

#Evite les conflits si des fichiers on le même nom que les règles
.PHONY: all clean fclean re