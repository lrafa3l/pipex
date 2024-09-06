# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 06:31:17 by lrafael           #+#    #+#              #
#    Updated: 2024/05/27 06:31:34 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = *.c
OBJ = *.o
RM = rm -f

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS) -I ./
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME);

re: fclean all
