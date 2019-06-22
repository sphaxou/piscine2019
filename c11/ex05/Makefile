# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 17:57:56 by vgallois          #+#    #+#              #
#    Updated: 2019/06/15 22:26:39 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= do-op
SRCS			= ft_do_op.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_atoi.c
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
OBJ				= $(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR			= ./
INCDIR			= ./

all:$(NAME)

$(SRCDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
