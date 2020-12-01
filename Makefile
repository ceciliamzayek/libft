# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmzayek <cmzayek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 15:19:17 by cmzayek           #+#    #+#              #
#    Updated: 2020/12/01 13:06:41 by cmzayek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -c

IFLAGS		=	-I$(INC_PATH)

AR			=	ar

ARFLAGS		=	-rcs

RM			=	rm

RMFLAGS		=	-rf

.SUFFIXES:	.c .o .h

INC			=	libft.h

SRC			=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strnstr.c	\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c

SRC_BONUS	=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(INC)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
			$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			$(RM) $(RMFLAGS) $(NAME) a.out

re:			fclean all

bonus:		$(OBJ_BONUS) $(INC)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ_BONUS)

.PHONY:		all fclean clean re bonus
