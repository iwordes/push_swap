/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/15 19:19:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr
#define B b->arr

#define A1 A[a->len - 1]
#define A2 A[a->len - 2]

#define OP(O) op__(#O, op_##O, a, b)

#define OPM(K) (K % a->len)
#define OPT(K) OPM(K) - ((OPM(K) > a->len / 2) ? a->len : 0)


#define I (b->len - 1 - ((o + i) % b->len))

/*
** Return the cost of sorting the value N into B at offset O.
*/

static int	cost(t_stack *b, int o, int n)
{
	int		i;

	i = 0;
	while (i < b->len && B[I] >= n)
		i += 1;
	return (i);
}

/*
** Determine the best sort from A -> B.
*/

#define CUR B[(bi < 0) ? ~bi : (b->len - 1) - bi]
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
	while (ABS(ai) < H2(a->len))
	{
		// 2a. Find the cost to move A[ai] -> B.
		bi = cost(b, bo, CUR);

		// 2b. Update the best move.
		if (NEW < OLD)
		{
			*ra = ai;
			*rb = OPT(bo + bi);
		}

		ai = -ai + (ai <= 0);
	}
}

void		sort(t_stack *a, t_stack *b)
{
	int		rot1;
	int		rot2;

	// 1. A -> B
	op_pb(a, b);
	op_pb(a, b);

	// 2. A ~> B
	while (a->len/* > 2*/)
	{
		// 1a. Find the most effective move from A to B.
		best(a, b, &rot1, &rot2);

		// 1b. Rotate A & B.
		op__srot(a, rot1, 'a');
		op__srot(b, rot2, 'b');

		// 1c. Push -> B.
		op_pb(a, b);
	}

	// 2. B -> A
	while (b->len)
		op_pa(a, b);

	// 3. Align A
	op__srot(a, check_ps(a), 'a');
}
