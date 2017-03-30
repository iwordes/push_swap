/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 20:08:27 by iwordes          ###   ########.fr       */
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

#define CUR A[a->len - 1 - o]
#define ROTOPT (mo > a->len / 2 + (a->len & 1)) ? mo - a->len : mo

static int	find_min(t_stack *a)
{
	int		o;
	int		mn;
	int		mo;

	o = 0;
	mn = INT_MAX;
	mo = INT_MAX;
	while (o < a->len)
	{
		if (CUR < mn)
		{
			mn = CUR;
			mo = o;
		}
		o += 1;
	}
	return (ROTOPT);
}

void		sort(t_stack *a, t_stack *b)
{
	int		o;

	while (a->len > 1)
	{
		o = find_min(a);
		if (o < 0)
			while (o++)
				OP(rra);
		else
			while (o--)
				OP(ra);
		OP(pb);
	}
	while (b->len != 0)
		OP(pa);


	ft_eprintf("\e[92m[");
	for (int k = a->len - 1; k >= 0; k--)
		ft_eprintf("%s%d", (k != a->len - 1) ? ", " : "", a->arr[k]);
	ft_eprintf("]\e[0m\n");
}
