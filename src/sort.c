/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 13:25:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort Mk.II: Insertion
*/

#define A a->arr
#define B b->arr
#define S s->arr

#define A1 A[a->len - 1]
#define A2 A[a->len - 2]

#define B1 B[b->len - 1]
#define B2 B[b->len - 2]

#define TA A1
#define TB B1
#define BA A[0]
#define BB B[0]

#define OP(O) op__(#O, op_##O, a, b)

// 1. Insert half of A into B, rotating B as necessary to sort input.
// 2. Sort A.
// 3. Merge into A.

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
	//ft_eprintf("\e[95mSIM\e[0m\n");
	//ft_eprintf("a: %ld\n", a);
	//ft_eprintf("b->max: %ld\n", b->max);
	//ft_eprintf("a > b->max: %ld\n", a > b->max);
	while (i < b->len && a < B[I])
	{
		//ft_eprintf("B[%d]: %d\n", I, B[I]);
		i += 1;
	}
	//ft_eprintf("\e[95m/SET\e[0m\n");
	return (i);
}

#define CUR A[(ai < 0) ? ~ai : (a->len - 1) - ai]
#define ABS1 (unsigned)(ABS(ai) + ABS(bi) + ABS(bo))
#define ABS2 (unsigned)(ABS(*best_a) + ABS(*best_b))

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
		//ft_eprintf("ai: %d | bo: %d\n", ai, bo);
		//ft_eprintf("A[%d]: %d\n", (ai < 0) ? ~ai : (a->len - 1) - ai, CUR);
		bi = sim(CUR, b, bo);
		//ft_eprintf("ai: %d | bi: %d | bo: %d\n", ai, bi, bo);
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

		//ft_eprintf("best: a%d -> b%d\n", best_a, best_b);

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

/*
static void	sort2(t_stack *a, t_stack *b)
{
	// ...
}

static void	merge(t_stack *a, t_stack *b)
{
	// ...
}
*/

void		sort(t_stack *a, t_stack *b)
{
	/*ft_eprintf("----\n");
	ft_eprintf("a->min: %i\n", a->min);
	ft_eprintf("a->max: %i\n", a->max);
	ft_eprintf("b->min: %i\n", b->min);
	ft_eprintf("b->max: %i\n", b->max);
	ft_eprintf("----\n");
	for (int w = 0xFFFFF; w; w--);*/

	sort1(a, b);
	//sort2(a, b);
	//merge(a, b);

	return;
	ft_eprintf("\e[92m[");
	for (int k = a->len - 1; k >= 0; k--)
		ft_eprintf("%s%d", (k != a->len - 1) ? ", " : "", a->arr[k]);
	ft_eprintf("]\e[0m\n");
}
