/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:11:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 14:50:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr
#define ARG argv[argc]

static void	validate(t_stack *a, long n, int argc, char **argv)
{
	int		i;

	i = 0;
	if (n == 0 && *ARG != '0')
		error();
	if (n < INT_MIN || n > INT_MAX)
		error();
	while (i < a->len - argc)
	{
		if (n == A[i])
			error();
		i += 1;
	}
}

static void	var_(t_stack *a, t_stack *b, int argc)
{
	b->len = 0;
	a->len = argc;
	a->min = INT_MAX;
	b->min = INT_MAX;
	a->max = INT_MIN;
	b->max = INT_MIN;
	MGUARD(a->arr = MALT(int, argc));
	MGUARD(b->arr = MALT(int, argc));
}

void		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	long	n;

	if (argc == 0)
		error();
	var_(a, b, argc);
	while (argc)
	{
		argc -= 1;
		ITER(ARG, ft_isspace(*ARG));
		n = ft_atol(ARG);
		if (*ARG == '+' || *ARG == '-')
			ARG += 1;
		validate(a, n, argc, argv);
		A[a->len - argc - 1] = n;
		(n < a->min) && (a->min = n);
		(n > a->max) && (a->max = n);
		ITER(ARG, ft_isdigit(*ARG));
		if (*ARG != 0)
			error();
	}
}
