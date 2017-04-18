/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:45:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/18 13:37:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort the remaining elements in A.
*/

#define A (a->arr + a->len - 1)
#define N A[-((o + r1) % a->len)]
#define I ((o + r1 + r2 - 1) % a->len)
#define OP(O) op__(#O, op_##O, a, b)

static int	back(t_stack *a, int o, int r1)
{
	int		r2;

	r2 = 0;
	while (r1 + r2 != 0 && N < A[-I])
		r2 -= 1;
	return (r2);
}

#define AL1 a->len
#define AL2 (a->len - 1)
#define OPT1(K) (K % AL1) - (((K % AL1) > AL1 / 2) ? AL1 : 0)
#define OPT2(K) ((ABS(K) > AL2 / 2) ? K + AL2 : K)

#define COST (unsigned)(ABS(OPT1(o + r1)) + ABS(OPT2(r2)))
#define BEST (unsigned)(ABS(*best_r1) + ABS(*best_r2))

static void	best(t_stack *a, int *best_r1, int *best_r2)
{
	int		r1;
	int		r2;
	int		o;

	o = 0;
	r1 = 0;
	r2 = 0;
	*best_r1 = INT_MAX;
	*best_r2 = INT_MAX;
	while (A[-o] != a->min)
		o += 1;
	while (r1 < a->len)
	{
		r2 = back(a, o, r1);
		if (r2 != 0 && COST < BEST)
		{
			*best_r1 = OPT1(o + r1);
			*best_r2 = OPT2(r2);
		}
		r1 += 1;
	}
}

void	sort2(t_stack *a, t_stack *b)
{
	int		r1;
	int		r2;

	if (a->len <= 2)
		return ;
	while (check_asc(a) == INT_MIN)
	{
		best(a, &r1, &r2);
		op__srot(a, r1, 'a');
		OP(pb);
		op__srot(a, r2, 'a');
		OP(pa);
	}
}
