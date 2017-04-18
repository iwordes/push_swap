/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:47:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 16:17:22 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#ifndef CHECKER

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	argc -= 1;
	argv += 1;
	init(&a, &b, argc, argv);
	if (check_asc(&a) != 0)
	{
		sort1(&a, &b);
		sort2(&a, &b);
		merge(&a, &b);
	}
	free(a.arr);
	free(b.arr);
	return (0);
}

#else

static t_op	g_op[] =
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

t_main	g_mn;

static void	do_op(t_stack *a, t_stack *b, char *op)
{
	unsigned	i;

	i = ~0;
	while (g_op[i += 1].str != NULL)
		if (ft_strequ(g_op[i].str, op))
		{
			g_op[i].fn(a, b);
			if (g_mn.show_vis)
				show(a, b, op);
			break ;
		}
	free(op);
	if (g_op[i].str == NULL)
		error();
	g_mn.ops += 1;
}

static t_arg	g_arg[] =
{
	{ "c", arg_cnt, 0 },
	{ "v", arg_vis, 0 },
	//{ "w", arg_wait, 0 },
	{ NULL, NULL, 0 }
};

int			main(int argc, char **argv)
{
	char	*op;
	t_stack	a;
	t_stack	b;

	g_mn.ops = 0;
	g_mn.show_ops = 0;
	g_mn.show_vis = 0;
	arg_parse(&argc, &argv, g_arg);
	init(&a, &b, argc, argv);
	if (g_mn.show_vis)
		show(&a, &b, "");
	while (ft_readln(0, &op) > 0)
		do_op(&a, &b, op);
	free(op);
	if (check_asc(&a) == 0 && b.len == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (g_mn.show_ops)
		ft_printf("%u\n", g_mn.ops);
	free(a.arr);
	free(b.arr);
	return (0);
}

#endif
