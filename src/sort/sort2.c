/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:45:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 15:46:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort the remaining elements in A.
*/

#define A (a->arr + a->len - 1)
#define I ((o + r2) % a->len)

#define OP(O) op__(#O, op_##O, a, b)

static int	cost(t_stack *a, int o, int n)
{
	int		seen;
	int		r2;

	r2 = 0;
	seen = 0;
	while (r2 < a->len && n >= A[-I])
	{
		if (n == A[I])
			seen = 1;
		r2 += 1;
	}
	return (o + r2 - seen);
}

#define NEW (unsigned)(ABS(OPT(r1)) + ABS(OPT(r2)))
#define OLD (unsigned)(ABS(*rot1) + ABS(*rot2))

#define OPM(K) (K % a->len)
#define OPT(K) OPM(K) - ((OPM(K) > a->len / 2) ? a->len : 0)

static void	best(t_stack *a, int *rot1, int *rot2)
{
	int		r1;
	int		r2;
	int		o;

	o = 0;
	r1 = 0;
	r2 = 0;
	*rot1 = INT_MAX;
	*rot2 = INT_MAX;

	while (A[-o] != a->min)
		o += 1;

	while (r1 < a->len)
	{
		r2 = cost(a, o, A[-r1]) - r1;
		if (NEW < OLD)
		{
			*rot1 = OPT(r1);
			*rot2 = OPT(r2);
		}
		r1 += 1;
	}
}

void	sort2(t_stack *a, t_stack *b)
{
	int		rot1;
	int		rot2;
	int		rot3;

	if (a->len == 3 && A[0] > A[1])
		OP(sa);
	if (a->len <= 3)
		return ;
	while ((rot3 = check_asc(a)) == INT_MIN)
	{
		best(a, &rot1, &rot2);
		op__srot(a, rot1, 'a');
		OP(pb);
		op__srot(a, rot2, 'a');
		OP(pa);
	}
	op__srot(a, rot3, 'a');
}
