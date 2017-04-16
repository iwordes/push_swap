/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:05:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 14:58:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define I(IX) (s->len - 1 - ((o + IX) % s->len))
#define I1 I(i)
#define I2 I(i + 1)

int		check_desc(t_stack *s)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (S[I1] != s->max)
		o += 1;
	while (i + 1 < s->len)
	{
		if (S[I1] < S[I2])
			return (INT_MIN);
		i += 1;
	}
	return (o);
}
