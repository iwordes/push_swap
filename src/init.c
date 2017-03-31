/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:11:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 19:33:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define ISDIG(C) (C >= '0' && C <= '9')

static bool	val_num(char *num)
{
	while (ft_isspace(*num))
		num += 1;
	if (*num == '+' || *num == '-')
		num += 1;
	while (ISDIG(*num) && *num != 0)
		num += 1;
	return (*num == 0 || ft_isspace(*num));
}

void		init_(t_stack *a, t_stack *b, int argc)
{
	b->len = 0;
	a->len = argc - 1;
	a->min = INT_MAX;
	b->min = INT_MAX;
	a->max = INT_MIN;
	b->max = INT_MIN;
	MGUARD(a->arr = MALT(int, argc - 1));
	MGUARD(b->arr = MALT(int, argc - 1));
}

void		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	long	n;

	i = 1;
	init_(a, b, argc);
	while (i < argc)
	{
		if (!val_num(argv[i]))
			error();
		//        v l
		n = ft_atoi(argv[i]);
		if (n > INT_MAX)
			error();
		a->arr[a->len - i] = n;
		(n < a->min) && (a->min = n);
		(n > a->max) && (a->max = n);
		i += 1;
	}
	if (i == 1)
		error();
}
