/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:05:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/18 13:09:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S (s->arr + s->len - 1)
#define I1 ((o + i) % s->len)
#define I2 ((o + i + 1) % s->len)

int		check_desc(t_stack *s)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (S[-o] != s->max)
		o += 1;
	while (i + 1 < s->len)
	{
		if (S[-I1] < S[-I2])
			return (INT_MIN);
		i += 1;
	}
	return (o);
}
