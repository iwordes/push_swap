# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 19:45:22 by iwordes           #+#    #+#              #
#    Updated: 2017/04/30 19:55:29 by iwordes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap
AUTHOR = iwordes

CC     = gcc
CF    += -Wall -Wextra -Werror -I include
CF    += -L lib/ft -lft -I lib/ft/include
CF    += -L lib/arg -larg -I lib/arg

SRC_OP = pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c z_.c z_rot.c z_rrot.c z_swap.c z_srot.c
SRC    = check_asc.c check_desc.c error.c init.c main.c minmax.c show.c
SRC   += sort/merge.c sort/sort1.c sort/sort2.c sort/score.c sort/smarot.c
SRC   += sort/ropt.c sort/scoropt.c
SRC   += arg/cnt.c arg/vis.c
SRC   += $(addprefix op/,$(SRC_OP))
SRC   := $(addprefix src/,$(SRC))

# ------------------------------------------------------------------------------
# Phony Targets

.PHONY: all
all: $(NAME) checker

.PHONY: clean
clean:
	rm -rf build
	make -C lib/arg fclean
	make -C lib/ft fclean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f checker

.PHONY: re
re: fclean all

.PHONY: test
test:
	make
	n=`echo $$(~/test/rand $N)` sh -c './push_swap $$n | ./checker -cv $$n'

# ------------------------------------------------------------------------------
# Real Targets

$(NAME): $(SRC) lib/ft/libft.a
	$(CC) $(CF) -o $@ $^

checker: $(SRC) lib/ft/libft.a lib/arg/libarg.a
	$(CC) $(CF) -D CHECKER -o $@ $^

%.a:
	make -C $(@D)
