# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwordes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 19:45:22 by iwordes           #+#    #+#              #
#    Updated: 2017/03/21 19:45:22 by iwordes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap
AUTHOR = iwordes

CC     = gcc
CF    += -Wall -Wextra -Werror -I include
CF    +=

SRC    = # Add *.c files here
SRC   := $(addprefix src/,$(SRC))

# ------------------------------------------------------------------------------
# Phony Targets

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

# ------------------------------------------------------------------------------
# Real Targets

$(NAME): $(SRC)
	$(CC) $(CF) -o $@ $^

