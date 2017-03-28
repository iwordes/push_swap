/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:47:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/28 14:11:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#ifndef CHECKER

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init(&a, &b, argc, argv);
	if (a->len > 1)
		sort(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}

#else

static char	*g_opc[] =
{
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	"sa",
	"sb",
	"ss",
	NULL
};

static void	(*g_op[])(t_stack*, t_stack*) =
{
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr,
	op_sa,
	op_sb,
	op_ss
};

int			main(int argc, char **argv)
{
	char	*op;
	size_t	i;
	t_stack	a;
	t_stack	b;

	init(&a, &b, argc, argv);
	while (ft_readln(0, &op) > 0)
	{
		i = ~0;
		while (g_opc[i += 1] != NULL)
			if (ft_strequ(g_opc[i], op))
			{
				g_op[i](&a, &b);
				break ;
			}
		free(op);
		if (g_opc[i] == NULL)
			error();
	}
	free(op);
	if (check(&a, &b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free(a.arr);
	free(b.arr);
	return (0);
}

#endif
