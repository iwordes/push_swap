/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/28 16:00:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort Mk.II: Insertion
*/

#define A a->arr
#define B b->arr
#define S s.arr

#define A1 A[a->len - 1]
#define A2 A[a->len - 2]
#define S1 S[s.len - 1]
#define S2 S[s.len - 2]

#define OP(O) op__(#O, op_##O, a, b)

static int	try_sort(t_stack *a, UINT o)
{
	int		n;

	while (o--)
		op__rrot(a);
	o = 0;
	n = A1;
	op__rot(a);
	a->len -= 1;
	while (n > A1)
	{
		op__rrot(a);
		o += 1;
	}
	return (o >= a->len / 2 ? a->len - o : o);
}

static void	do_sort(t_stack *a, t_stack *b, int o, int to)
{
	if (o < 0)
		while (o++)
			OP(ra);
	else
		while (o--)
			OP(rra);
	OP(pb);
	if (to < 0)
		while (to++)
			OP(ra);
	else
		while (to--)
			OP(rra);
	OP(pa);
}

static void	find_sort(t_stack *a, t_stack *b)
{
	t_stack	s;
	UINT	o;
	UINT	fo;
	int		sh;
	int		cache;

	o = 0;
	fo = 0;
	sh = INT_MIN;
	while (o < a->len)
	{
		s = *a;
		cache = try_sort(a, o);
		if (o + ABS(cache) < (UINT)ABS(sh))
		{
			sh = cache;
			fo = o;
		}
		o += 1;
	}
	do_sort(a, b, (fo >= a->len / 2) ? a->len - fo : fo, sh);
}

void		sort(t_stack *a, t_stack *b)
{
	int		o;

	while ((o = check_ps(a)) == INT_MIN)
		find_sort(a, b);
	if (o < 0)
		while (o++)
			OP(ra);
	else
		while (o--)
			OP(rra);
}
