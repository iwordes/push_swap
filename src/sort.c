/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 15:47:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort Mk.II: Insertion
*/

#define A a->arr
#define B b->arr
#define S s.arr

#define TA A[a->len - 1]
#define TB B[b->len - 1]

#define OP(O) op__(#O, op_##O, a, b)

#define CUR A[(o < 0) ? ~o : a->len - 1 - o]

static int	find(t_stack *a, t_stack *b)
{
	int		o;

	o = 0;
	while (ABS(o) < H2(a->len))
	{
		// ...
		(void)b;
		o = -o + (o <= 0);
	}
	return (INT_MIN);
}

void		sort(t_stack *a, t_stack *b)
{
	int		o;

	while (a->len > 1)
	{
		o = find(a, b);
		op__srot(a, o, true);
		OP(pb);
	}
	while (b->len != 0)
		OP(pa);


	ft_eprintf("\e[92m[");
	for (int k = a->len - 1; k >= 0; k--)
		ft_eprintf("%s%d", (k != a->len - 1) ? ", " : "", a->arr[k]);
	ft_eprintf("]\e[0m\n");
}
