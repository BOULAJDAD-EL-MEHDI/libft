# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 12:52:28 by eboulajd          #+#    #+#              #
#    Updated: 2025/10/27 14:47:04 by eboulajd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./

LIBC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
      ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c 

ADDITIONAL = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS = ${LIBC} ${ADDITIONAL}

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}: ${OBJS}
	ar -rsc ${LIB} ${OBJS}

all: ${LIB}

clean:
	rm -f ${OBJS}

fclean: clean;
	fm -f ${lib}

re: fclean all

.PHONY: clean
