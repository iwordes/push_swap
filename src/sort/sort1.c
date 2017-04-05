/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 13:37:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Invert, ((offset), cap)
#define I (b->len - 1 - ((bo + i) % b->len))

#define OPT(UI, S) (UI > H2(S->len) ? UI - S->len : UI)
#define CUR A[(ai < 0) ? ~ai : (a->len - 1) - ai]
#define ABS1 (unsigned)(ABS(ai) + ABS(bi) + ABS(bo))
#define ABS2 (unsigned)(ABS(*best_a) + ABS(*best_b))

/*
** The goal of sim() and best() is to determine WHERE to insert TA into B
** and HOW to insert it there.
*/

static int	sim(int a, t_stack *b, int bo)
{
	int		i;

	i = 0;
	while (i < b->len && a < B[I])
		i += 1;
	return (OPT(i));
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
		bi = sim(CUR, b, bo);
		if (ABS1 < ABS2)
		{
			//ft_eprintf("\e[96m[SET]\e[0m\n");
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

		op__srot(a, best_a, 'a');
		op__srot(b, best_b, 'b');
		// op__goto(a, best_a);
		// op__goto(b, best_b);
		OP(pb);
	}
	while (b->len)
		OP(pa);
	o = check_ps(a);
	op__srot(a, o, 'a');
}
