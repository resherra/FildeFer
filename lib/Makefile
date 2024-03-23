# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 11:21:31 by recherra          #+#    #+#              #
#    Updated: 2024/01/07 16:40:38 by resherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c  ft_memmove.c  ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SBONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}
NAME = libft.a
OBONUS = ${SBONUS:.c=.o}
all: ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

bonus: ${OBONUS}

${OBONUS}:
	${CC} ${CFLAGS} -c $(SBONUS)
	ar -rcs ${NAME} ${OBONUS}

clean:
	rm -rf ${OBJ} ${OBONUS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
