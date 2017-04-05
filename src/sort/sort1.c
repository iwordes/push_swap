/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 12:37:12 by iwordes          ###   ########.fr       */
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

static void	best(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
	int		ai;
	int		bi;
	int		bo;

	ai = 0;
	bi = 0;
	bo = 0;
	*best_a = INT_MAX;
	*best_b = INT_MAX;
	while (B[bo] != b->min)
		bo += 1;
	while (ABS(ai) < H2(a->len))
	{
		bi = sim(TA, b, bo);
		ft_eprintf("Insert [%d](%d) at [%d]\n", ai, TA, bi + bo);
		if (ai + bi + bo < *best_a + *best_b)
		{
			*best_a = ai;
			*best_b = bi + bo;
		}
		ai = -ai + (ai <= 0);
	}
}

void		sort1(t_stack *a, t_stack *b)
{
	int		best_a;
	int		best_b;
	int		o;

	OP(pb);
	OP(pb);
	if (B1 < B2)
		OP(sb);
	while (a->len)
	{
		best(a, b, &best_a, &best_b);
		ft_eprintf("best: a%d b%d\n", best_a, best_b);
		op__srot(a, best_a, 'a');
		op__srot(b, best_b, 'b');
		// op__goto(a, best_a);
		// op__goto(b, best_b);
		OP(pb);
	}
	while (b->len)
		OP(pa);
	o = check_ps(a);
	ft_eprintf("Final offset: %d\n", o);
	op__srot(a, o, 'a');
}
