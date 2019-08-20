# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anain <anain@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 03:28:17 by anain             #+#    #+#              #
#    Updated: 2017/08/02 18:52:00 by anain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstmap.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c ft_lstadd.c \
ft_lstnew.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putendl.c \
ft_putnbr_fd.c ft_putstr.c ft_putendl_fd.c ft_putstr_fd.c ft_isdigit.c \
ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c ft_isupper.c \
ft_islower.c ft_itoa.c ft_atoi.c ft_putstr.c ft_strlen.c ft_memalloc.c \
ft_memmove.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memset.c \
ft_memdel.c ft_toupper.c ft_tolower.c ft_strstr.c ft_strsplit.c ft_strnstr.c \
ft_strnew.c ft_strnequ.c ft_strequ.c ft_strncpy.c ft_strcpy.c ft_strncat.c \
ft_strcat.c ft_strlcat.c ft_strdup.c ft_strcmp.c ft_strncmp.c ft_strjoin.c \
ft_strchr.c ft_strrchr.c ft_strdel.c ft_bzero.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strtrim.c get_next_line.c \
ft_min.c ft_max.c ft_ispositive.c ft_square.c ft_root.c ft_atoi_base.c \
ft_strjoin_and_free.c ft_strstr_caseins.c ft_atod.c ft_error.c\

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC) libft.h
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:  clean
	/bin/rm -f $(NAME)

re: fclean all
