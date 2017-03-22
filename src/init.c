/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:11:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/22 15:05:22 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define ISDIG(C) (C >= '0' && C <= '9')

bool		val_num(char *num)
{
	while (ft_isspace(*num))
		num += 1;
	if (*num == '+' || *num == '-')
		num += 1;
	while (ISDIG(*num) && *num != 0)
		num += 1;
	return (*num == 0 || ft_isspace(*num));
}

void		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	long	n;

	i = 1;
	b->len = 0;
	a->len = argc - 1;
	MGUARD(a->arr = MALT(int, argc - 1));
	MGUARD(b->arr = MALT(int, argc - 1));
	while (i < argc)
	{
		if (!val_num(argv[i]))
			error();
		//        v l
		n = ft_atoi(argv[i]);
		if (n > INT_MAX)
			error();
		a->arr[a->len - i] = n;
		i += 1;
	}
	if (i == 1)
		error();
}
