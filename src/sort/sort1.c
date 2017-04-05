/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 11:42:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Invert, ((offset), cap)
#define I (b->len - 1 - ((bo + i) % b->len))

/*
** The goal of sim() and best() is to determine WHERE to insert TA into B
** and HOW to insert it there.
*/

static int	sim(int a, t_stack *b, int bo)
{
	int		i;

	i = 0;
	while (a < B[I])
		i += 1;
	return (i);
}

static int	best(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
	int		ai;
	int		bi;
	int		bo;

	ai = 0;
	bi = 0;
	bo = 0;
	best_a = INT_MAX;
	best_b = INT_MAX;
	while (B[bo] != b->min)
		bo += 1;
	while (ABS(ai) < H2(a->len))
	{
		bi = sim(TA, b, bo);
		ft_eprintf("Insert (%d) at [%d]\n", TA, bi + bo);
		if (ai + (bi + bo) < *best_a + *best_b)
		{
			*best_a = ai;
			*best_b = bi + bo;
		}
		ai = -ai + (ai <= 0);
	}
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
