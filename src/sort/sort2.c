/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/30 12:10:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A (a->arr + a->len - 1)
#define B (b->arr + b->len - 1)

#define OH2(I, S) ((I % S->len) > S->len / 2)
#define OPT(I, S) ((I % S->len) - (OH2(I, S) ? S->len : 0))

#define I ((o + r) % a->len)

static int	cost(t_stack *a, int o, int n)
{
	int		r;

	r = 0;
	while (r < a->len && n > A[-I])
		r += 1;
	return (o + r);
}

#define COST (scoropt(ra, rb, a, b))
#define BEST (score(*best_ra, *best_rb))

static void	best(t_stack *a, t_stack *b, int *best_ra, int *best_rb)
{
	int		ra;
	int		rb;
	int		o;

	o = 0;
	ra = 0;
	rb = 0;
	*best_ra = INT_MAX;
	*best_rb = INT_MAX;
	while (A[-o] != a->min)
		o += 1;
	while (rb < b->len)
	{
		ra = cost(a, o, B[-rb]);
		if (COST < BEST)
		{
			*best_ra = ra;
			*best_rb = rb;
			ropt(best_ra, best_rb, a, b);
		}
		rb += 1;
	}
}

void		sort2(t_stack *a, t_stack *b)
{
	int		ra;
	int		rb;

	while (b->len)
	{
		best(a, b, &ra, &rb);
		smarot(a, b, ra, rb);
		OP(pa);
	}
	op__srot(a, check_asc(a), 'a');
}
