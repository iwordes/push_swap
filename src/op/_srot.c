/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _srot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:43:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 19:55:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	putop(char *op, char s)
{
	if (s)
	{
		ft_putstr(op);
		write(1, &s, 1);
		write(1, "\n", 1);
	}
}

void	op__srot(t_stack *s, int o, char name)
{
	o %= s->len;
	if (o > s->len / 2)
		o -= s->len;
	if (o < 0)
		while (o++)
		{
			putop("rr", name);
			op__rrot(s);
		}
	else
		while (o--)
		{
			putop("r", name);
			op__rot(s);
		}
}
