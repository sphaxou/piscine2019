# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 17:57:56 by vgallois          #+#    #+#              #
#    Updated: 2019/06/11 19:13:13 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
SRCS			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
CC				= gcc
FLAGS			= -Wall -Werror -Wextra

SRCDIR			= ./srcs/
INCDIR			= ./includes/
all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -c -I $(INCDIR) $(addprefix $(SRCDIR), $(SRCS))
