# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 17:57:56 by vgallois          #+#    #+#              #
#    Updated: 2019/06/23 19:58:41 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_tail
SRCS			= $(shell ls | grep -E "ft_.+\.c") \
				  readinput.c\
				  main.c \
				  tail_error.c
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
OBJ				= $(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR			= ./
INCDIR			= ./

all: $(NAME)

$(SRCDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

nice: all clean
