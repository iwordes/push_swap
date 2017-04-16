/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:06:25 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/16 14:57:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define I(IX) (s->len - 1 - ((o + IX) % s->len))
#define I1 I(i)
#define I2 I(i + 1)

int		check_asc(t_stack *s)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (S[I1] != s->min)
		o += 1;

	ft_eprintf("\e[92masc\e[0m\n  o: %d\n", o);

	while (i + 1 < s->len)
	{
		ft_eprintf("  cmp: %d, %d\n", S[I1], S[I2]);

		if (S[I1] > S[I2])
			return (INT_MIN);
		i += 1;
	}
	return (o);
}
