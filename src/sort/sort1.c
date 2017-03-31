/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 19:49:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	best(t_stack *s, int n)
{
	int		b;
	int		i;

	b = 0;
	i = 1;
	while (S[b] != s->min)
		b += 1;
	while (i < s->len && !(S[I - 1] > n && n > S[I]))
		i += 1;
	return (b + i);
}

void		sort1(t_stack *a, t_stack *b)
{
	int		i;

	OP(pb);
	OP(pb);
	if (B1 < B2)
		OP(sb);
	i = a->len /*/ 2 - 1 + (a->len & 1)*/;
	while (i--)
	{
		op__srot(b, best(b, TA), 'b');
		OP(pb);
	}
}
