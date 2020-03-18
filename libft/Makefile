# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 17:29:02 by rfork             #+#    #+#              #
#    Updated: 2020/03/11 17:18:28 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = is/ft_isalnum.c \
       is/ft_isalpha.c \
       is/ft_isascii.c \
       is/ft_isdigit.c \
       is/ft_isprint.c \
       is/ft_isupper.c \
       is/ft_islower.c \
       is/ft_isspace.c \
       is/ft_iscntrl.c \
       is/ft_isblank.c \
       is/ft_tolower.c \
       is/ft_toupper.c \
       list/ft_lstadd.c \
       list/ft_lstdel.c \
       list/ft_lstdelone.c \
       list/ft_lstiter.c \
       list/ft_lstmap.c \
       list/ft_lstnew.c \
       memory/ft_memalloc.c \
       memory/ft_memccpy.c \
       memory/ft_memchr.c \
       memory/ft_memcmp.c \
       memory/ft_memcpy.c \
       memory/ft_memdel.c \
       memory/ft_memmove.c \
       memory/ft_memset.c \
       put/ft_putchar.c \
       put/ft_putchar_fd.c \
       put/ft_putendl.c \
       put/ft_putendl_fd.c \
       put/ft_putnbr.c \
       put/ft_putnbr_fd.c \
       put/ft_putstr.c \
       put/ft_putstr_fd.c \
       string/ft_strcat.c \
       string/ft_strchr.c \
       string/ft_strclr.c \
       string/ft_strcmp.c \
       string/ft_strcpy.c \
       string/ft_strdel.c \
       string/ft_strdup.c \
       string/ft_strequ.c \
       string/ft_striter.c \
       string/ft_striteri.c \
       string/ft_strjoin.c \
       string/ft_strlcat.c \
       string/ft_strlen.c \
       string/ft_strmap.c \
       string/ft_strmapi.c \
       string/ft_strncat.c \
       string/ft_strncmp.c \
       string/ft_strncpy.c \
       string/ft_strnequ.c \
       string/ft_strnew.c \
       string/ft_strnstr.c \
       string/ft_strrchr.c \
       string/ft_strsplit.c \
       string/ft_strstr.c \
       string/ft_strsub.c \
       string/ft_strtrim.c \
       string/ft_count_words.c \
       other/ft_atoi.c \
       other/ft_itoa.c \
       other/ft_bzero.c \
	   other/get_next_line.c \
	   complex/ft_cplxadd.c \
	   complex/ft_cplxsub.c \
	   complex/ft_cplxmul.c \
	   complex/ft_cplxdiv.c
OBJS = $(SRCS:.c=.o)
INCLUDES = libft.h

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		gcc -Wall -Wextra -Werror -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
