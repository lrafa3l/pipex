# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 07:17:54 by lrafael           #+#    #+#              #
#    Updated: 2024/05/14 07:17:57 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_isalpha.c	\
	ft_isdigit.c 		\
	ft_isalnum.c 		\
	ft_isascii.c 		\
	ft_isprint.c 		\
	ft_strlen.c 		\
	ft_memset.c 		\
	ft_bzero.c			\
	ft_memcpy.c 		\
	ft_memmove.c 		\
	ft_strlcpy.c 		\
	ft_strlcat.c 		\
	ft_toupper.c 		\
	ft_tolower.c 		\
	ft_strchr.c 		\
	ft_strrchr.c 		\
	ft_strncmp.c 		\
	ft_memchr.c 		\
	ft_memcmp.c 		\
	ft_strnstr.c 		\
	ft_atoi.c 			\
	ft_calloc.c 		\
	ft_strdup.c 		\
	ft_substr.c 		\
	ft_strjoin.c 		\
	ft_strtrim.c 		\
	ft_split.c 		\
	ft_itoa.c 		\
	ft_strmapi.c 		\
	ft_striteri.c 		\
	ft_putchar_fd.c 	\
	ft_putstr_fd.c 		\
	ft_putendl_fd.c 	\
	ft_putnbr_fd.c		\
	ft_count_words.c

BONUS = ft_lstnew.c 	\
	ft_lstadd_front.c 	\
	ft_lstsize.c 		\
	ft_lstlast.c 		\
	ft_lstadd_back.c 	\
	ft_lstdelone.c 		\
	ft_lstclear.c 		\
	ft_lstiter.c 		\
	ft_lstmap.c

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
