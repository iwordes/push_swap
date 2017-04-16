/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:11:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 14:33:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr

static void	validate(t_stack *a, long n)
{
	int		i;

	i = 0;
	if (n < INT_MIN || n > INT_MAX)
		error();
	while (i < a->len)
	{
		if (n == A[i])
			error();
		i += 1;
	}
}

static void	init_stack(t_stack *a, int argc, char **argv)
{
	long	n;

	while (argc)
	{
		ITER(*argv, ft_isspace(**argv));
		n = ft_atol(*argv);
		if (**argv == '+' || **argv == '-')
			*argv += 1;
		if (n == 0 && **argv != '0')
			error();
		validate(a, n);
		A[a->len++] = n;
		(n < a->min) && (a->min = n);
		(n > a->max) && (a->max = n);
		ITER(*argv, ft_isdigit(**argv));
		if (**argv != 0)
			error();
		argc -= 1;
		argv += 1;
	}
}

void		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->len = 0;
	b->len = 0;
	a->max = INT_MIN;
	b->max = INT_MIN;
	a->min = INT_MAX;
	b->min = INT_MAX;
	MGUARD(a->arr = MALT(int, argc));
	MGUARD(b->arr = MALT(int, argc));
	if (argc == 0)
		error();
	else
		init_stack(a, argc, argv);
}
