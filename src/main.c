/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:47:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/15 20:23:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#ifndef CHECKER

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init(&a, &b, argc, argv);
	if (check_asc(&a) != 0)
		sort(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}

#else

t_op	g_op[] =
{
	{ "pa", op_pa },
	{ "pb", op_pb },
	{ "ra", op_ra },
	{ "rb", op_rb },
	{ "rr", op_rr },
	{ "rra", op_rra },
	{ "rrb", op_rrb },
	{ "rrr", op_rrr },
	{ "sa", op_sa },
	{ "sb", op_sb },
	{ "ss", op_ss },
	{ NULL, NULL }
};

int		main(int argc, char **argv)
{
	char	*op;
	size_t	i;
	t_stack	a;
	t_stack	b;

	init(&a, &b, argc, argv);
	show(&a, &b);

	unsigned	c = 0;

	while (ft_readln(0, &op) > 0)
	{
		i = ~0;
		while (g_op[i += 1].str != NULL)
			if (ft_strequ(g_op[i].str, op))
			{
				g_op[i].fn(&a, &b);
				if (argc < 100)
				{
					ft_putendl(op);
					show(&a, &b);
				}
				break ;
			}
		free(op);
		if (g_op[i].str == NULL)
			error();

		c += 1;
	}
	free(op);

	if (check_asc(&a) && b.len == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");

	ft_eprintf("%u ops\n", c);
	free(a.arr);
	free(b.arr);
	return (0);
}

#endif
