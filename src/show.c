/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:38:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 17:18:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr[i - 1]
#define B b->arr[i - 1]

#define S_

t_op	g_op[] =
{
	{ "pa", (void*)"\e[F\e[C\e[C\e[C\e[C<\n" },
	{ "pb", (void*)"\e[F\e[C\e[C\e[C\e[C>\n" },
	{ "ra", (void*)"\e[F\e[F\e[C\e[C^\n\n" },
	{ "rb", (void*)"\e[F\e[F\e[C\e[C\e[C\e[C\e[C\e[C^\n\n" },
	{ "rr", (void*)"\e[F\e[F\e[C\e[C^\e[C\e[C\e[C^\n\n" },
	{ "rra", (void*)"\e[F\e[F\e[C\e[Cv\n\n" },
	{ "rrb", (void*)"\e[F\e[F\e[C\e[C\e[C\e[C\e[C\e[Cv\n\n" },
	{ "rrr", (void*)"\e[F\e[F\e[C\e[Cv\e[C\e[C\e[Cv\n\n" },
	{ "sa", (void*)"\e[F\e[F\e[C\e[C%\n\n" },
	{ "sb", (void*)"\e[F\e[F\e[C\e[C\e[C\e[C\e[C\e[C%\n\n" },
	{ "ss", (void*)"\e[F\e[F\e[C\e[C%\e[C\e[C\e[C%\n\n" },
	{ NULL, NULL }
};

void	showop(const char *op)
{
	int	i;

	i = ~0;
	while (g_op[i += 1].str != NULL)
		if (ft_strequ(op, g_op[i].str))
		{
			ft_printf("\e[93m%s\e[0m", g_op[i].fn);
			break ;
		}
}

void	show(t_stack *a, t_stack *b, const char *op)
{
	int		i;

	i = MAX(a->len, b->len);
	ft_putstr(" _______\n");
	while (i > 0)
	{
		if (i <= a->len)
			ft_printf("|\e[91m%3d\e[0m|", A);
		else
			ft_putstr("|   |");
		if (i <= b->len)
			ft_printf("\e[96m%-3d\e[0m|\n", B);
		else
			ft_putstr("   |\n");
		i -= 1;
	}
	ft_putstr("|---|---|\n");
	ft_putstr("| \e[1;4;91mA\e[0m | \e[1;4;96mB\e[0m |\n");
	showop(op);
}
