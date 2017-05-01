/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/30 19:51:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A (a->arr + a->len - 1)
#define B (b->arr + b->len - 1)

#define OH2(I, S) ((I % S->len) > S->len / 2)
#define OPT(I, S) ((I % S->len) - (OH2(I, S) ? S->len : 0))

#define I ((o + r) % b->len)

static int	cost(t_stack *b, int o, int n)
{
	int		r;

	r = 0;
	while (r < b->len && n < B[-I])
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
	while (B[-o] != b->max)
		o += 1;
	while (ra < a->len)
	{
		rb = cost(b, o, A[-ra]);
		if (COST < BEST)
		{
			*best_ra = ra;
			*best_rb = rb;
			ropt(best_ra, best_rb, a, b);
		}
		ra += 1;
	}
}

void		sort1(t_stack *a, t_stack *b)
{
	UINT	thres;
	int		ra;
	int		rb;

	thres = (a->len / 10) * 4;
	if (a->len > 2)
		OP(pb);
	if (a->len > 2)
		OP(pb);
	ra = 0;
	rb = 0;
	while (a->len > 2 && score(ra, rb) < thres)
	{
		best(a, b, &ra, &rb);
		smarot(a, b, ra, rb);
		OP(pb);
	}
	while (a->len > 2)
		OP(pb);
}
