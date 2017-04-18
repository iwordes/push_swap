/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:06:25 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/18 12:48:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S (s->arr + s->len - 1)
#define I1 ((o + i) % s->len)
#define I2 ((o + i + 1) % s->len)

int		check_asc(t_stack *s)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (S[-o] != s->min)
		o += 1;
	while (i + 1 < s->len)
	{
		if (S[-I1] > S[-I2])
			return (INT_MIN);
		i += 1;
	}
	return (o);
}
