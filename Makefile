# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 08:12:32 by lrafael           #+#    #+#              #
#    Updated: 2024/09/06 07:16:53 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC	= cc
CFLAGS 	= -Wall -Wextra -Werror

SRCS	= pipex.c
OBJS 	= ${SRCS:.c=.o}

HEADER	= pipex.h

all: ${NAME}

%.o : %.c  ${HEADER} 
	@$(CC) ${CFLAGS} -c $< -o $@



${NAME}: ${OBJS}
	@echo "\n\t\t\033[34m\033[1m*** Compiling ***\033[0m \n"
	@make -s -C ./libft
	@$(CC) ${OBJS} -Llibft -lft -o ${NAME}
	@echo "\033c"
	@echo "\n\t\t\033[92m\033[1m ~ Pipex Compiled! ~ \n"

n:
	norminette .

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}
	@echo "\033c"
	@echo "\n\t\t\033[31m\033[1mDeleted! \n"

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@echo "\033c"
	@echo "\n\t\t\033[31m\033[1mEverything Deleted! \n"

re: fclean all

.PHONY: all n clean fclean re
