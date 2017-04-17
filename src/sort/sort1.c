/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 11:47:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr
#define B b->arr

#define A1 A[a->len - 1]
#define A2 A[a->len - 2]

#define OP(O) op__(#O, op_##O, a, b)

#define OPM(K) (K % b->len)
#define OPT(K) OPM(K) - ((OPM(K) > b->len / 2) ? b->len : 0)


#define I (b->len - 1 - ((o + i) % b->len))

/*
** Return the cost of sorting the value N into B at offset O.
*/

static int	cost(t_stack *b, int o, int n)
{
	int		i;

	i = 0;
	while (i < b->len && n > B[I])
		i += 1;
	return (i);
}

/*
** Determine the best sort from A -> B.
*/

#define CUR A[(ai < 0) ? ~ai : (a->len - 1) - ai]
#define NEW (unsigned)(ABS(ai) + ABS(OPT(bo + bi)))
#define OLD (unsigned)(ABS(*ra) + ABS(*rb))

static void	best(t_stack *a, t_stack *b, int *ra, int *rb)
{
	int		ai;
	int		bi;
	int		bo;

	ai = 0;
	bi = 0;
	bo = 0;
	*ra = INT_MAX;
	*rb = INT_MAX;

	// 1. Find the start of B.
	while (B[b->len - 1 - bo] != b->min)
		bo += 1;

	// 2. Simulate all sorts into B.
	while (ABS(ai) <= H2(a->len))
	{
		bi = cost(b, bo, CUR);
		if (NEW < OLD)
		{
			*ra = ai;
			*rb = OPT(bo + bi);
		}
		ai = -ai + (ai <= 0);
	}
}

void		sort1(t_stack *a, t_stack *b)
{
	int		rot1;
	int		rot2;

	OP(pb);
	OP(pb);
	while (a->len > 2)
	{
		best(a, b, &rot1, &rot2);
		op__srot(a, rot1, 'a');
		op__srot(b, rot2, 'b');
		OP(pb);
	}
}
