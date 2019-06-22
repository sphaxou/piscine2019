# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 17:57:56 by vgallois          #+#    #+#              #
#    Updated: 2019/06/11 23:21:58 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
SRCS			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
OBJ				= $(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR			= ./srcs/
INCDIR			= ./includes/

all:$(NAME)

$(SRCDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
