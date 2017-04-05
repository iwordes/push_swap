/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/05 10:46:51 by iwordes          ###   ########.fr       */
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

#define CUR A[(o < 0) ? ~o : a->len - 1 - o]

// 1. Insert half of A into B, rotating B as necessary to sort input.
// 2. Sort A.
// 3. Merge into A.

// TODO: Simplify
// Invert, ((offset), cap)
#define I s->len - 1 - ((b + i) % s->len)

static int	best(t_stack *s, int n)
{
	int		b;
	int		i;

	b = 0;
	i = 0;
	while (S[b] != s->min)
		b += 1;
	while (i < s->len && n <= S[I])
		i += 1;
	// Very close, but backwards??
	return (b + i);
}

static void	sort1(t_stack *a, t_stack *b)
{
	int		i;

	OP(pb);
	OP(pb);
	if (B1 < B2)
		OP(sb);
	// Prefers B getting the extra elem
	i = a->len /* / 2 - 1 + (a->len & 1) */;
	while (i--)
	{
		op__srot(b, best(b, TA), 'b');
		OP(pb);
	}
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
