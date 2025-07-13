#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sargevor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 20:22:20 by sargevor          #+#    #+#              #
#    Updated: 2025/02/06 20:39:36 by sargevor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

HEADER = libft.h

MANDATORY = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_strlcpy.c ft_strjoin.c ft_strlcat.c \
			ft_strdup.c ft_putchar_fd.c ft_substr.c ft_itoa.c ft_strchr.c ft_strncmp.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_split.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	   	ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(MANDATORY:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	 rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
