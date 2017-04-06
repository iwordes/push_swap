/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:41:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 17:34:34 by iwordes          ###   ########.fr       */
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


#define I (a->len - 1 - ((o + i) % a->len))

static int	sim(t_stack *a, int o, int n)
{
	int		i;

	i = 0;
	while (i < a->len && n > A[I])
		i += 1;
	return (i);
}

#define CUR B[(bi < 0) ? ~bi : (b->len - 1) - bi]
#define NEW (unsigned)(ABS(OPT(o + i)) + ABS(bi))
#define OLD (unsigned)(ABS(*best_a) + ABS(*best_b))

static void	best(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
	int		i;
	int		o;
	int		bi;

	i = 0;
	o = 0;
	bi = 0;
	*best_a = INT_MAX;
	*best_b = INT_MAX;

	// 1. Anchor the "zero" offset to the smallest number in A.
	while (A[a->len - 1 - o] != a->min)
		o += 1;

	// 2. Attempt all sorts into A.
	while (ABS(bi) < H2(b->len))
	{
		// 2a. Find the correct place to move B[bi] to A.
		i = sim(a, o, CUR);

		// 2b. If needed, update the "best move".
		if (NEW < OLD)
		{
			*best_a = OPT(o + i);
			*best_b = bi;
		}

		// 2c. Stagger: 0, 1, -1, 2, -2, ...
		bi = -bi + (bi <= 0);
	}
}

void		sort1(t_stack *a, t_stack *b)
{
	int		best_a;
	int		best_b;
	int		o;

	// 1. Push into B.
	while (a->len > 2)
		OP(pb);

	// 2. Sort into A.
	while (b->len)
	{
		// 2a. Find the most effective move from B to A
		best(a, b, &best_a, &best_b);

		// 2b. Select A[best_a]
		op__srot(a, best_a, 'a');

		// 2c. Select B[best_b]
		op__srot(b, best_b, 'b');

		// 2d. Move B[] -> A[]
		OP(pa);
	}

	// 3. Find the offset for sorted-A (if any)
	o = check_ps(a);

	// 4. Eliminate that offset.
	op__srot(a, o, 'a');
}
