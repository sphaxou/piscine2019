# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 17:57:56 by vgallois          #+#    #+#              #
#    Updated: 2019/06/23 20:01:08 by vgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_hexdump
SRCS			= $(shell ls | grep -E "ft_.+\.c") \
				  print_things.c\
				  readinput.c\
				  main.c 
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
