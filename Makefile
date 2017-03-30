# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 19:45:22 by iwordes           #+#    #+#              #
#    Updated: 2017/03/29 15:47:21 by iwordes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap
AUTHOR = iwordes

CC     = gcc
CF    += -Wall -Wextra -Werror -I include
CF    += -L lib/ft -l ft -I lib/ft/include

SRC_OP = pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c _.c _rot.c _rrot.c _swap.c
SRC    = check.c check_ps.c error.c init.c main.c sort.c show.c stk_cpy.c
SRC   += $(addprefix op/,$(SRC_OP))
SRC   := $(addprefix src/,$(SRC))

# ------------------------------------------------------------------------------
# Phony Targets

.PHONY: all
all: $(NAME) checker

.PHONY: clean
clean:
	rm -rf build
	make -C lib/ft fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test:
	make
	n=`echo $$(~/test/rand $N)` sh -c './push_swap $$n | ./checker $$n'

# ------------------------------------------------------------------------------
# Real Targets

$(NAME): $(SRC) lib/ft/libft.a
	$(CC) $(CF) -o $@ $^

checker: $(SRC) lib/ft/libft.a
	$(CC) $(CF) -D CHECKER -o $@ $^

lib/ft/libft.a:
	make -j7 -C lib/ft
