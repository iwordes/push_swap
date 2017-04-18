/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:45:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/18 11:32:21 by iwordes          ###   ########.fr       */
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
	while (r2 < a->len && n > A[-I])
	{
		if (n == A[I])
			seen = 1;
		r2 += 1;
	}
	return (o + r2 - seen);
}

#define AL1 a->len
#define AL2 (a->len - 1)
#define OPT1(K) (K % AL1) - (((K % AL1) > AL1 / 2) ? AL1 : 0)
#define OPT2(K) (K % AL2) - (((K % AL2) > AL2 / 2) ? AL2 : 0)

#define NEW (unsigned)(ABS(OPT1(r1)) + ABS(OPT2(r2)))
#define OLD (unsigned)(ABS(*rot1) + ABS(*rot2))



static void	best(t_stack *a, int *rot1, int *rot2)
{
	int		r1;
	int		r2;
	int		o;

	//static int	dump = 0;

	ft_eprintf("\e[96mbest\e[0m\n");
	o = 0;
	r1 = 0;
	r2 = 0;
	*rot1 = INT_MAX;
	*rot2 = INT_MAX;
	while (A[-o] != a->min)
		o += 1;
	ft_eprintf("  o: %d\n", o);
	while (r1 < a->len)
	{
		r2 = cost(a, o, A[-r1]) - r1;
		ft_eprintf("  %d, %d (%d, %d)\n", r1, r2, OPT1(r1), OPT2(r2));
		if (A[-r1] != a->min && OPT2(r2) != 0 && NEW < OLD)
		{
			ft_eprintf("  \e[92m^\e[0m\n");
			*rot1 = OPT1(r1);
			*rot2 = OPT2(r2);
		}

		//for (unsigned wait = ~0; wait > 5; wait -= 5);

		r1 += 1;
	}

	//for (unsigned wait = ~0; wait > 5; wait -= 2);

	//if (dump++ == -1)
	//	while(1);
}

void	sort2(t_stack *a, t_stack *b)
{
	int		r1;
	int		r2;

	if (a->len <= 2)
		return ;
	while (check_asc(a) == INT_MIN)
	{
		//show(a, b, "");

		best(a, &r1, &r2);
		op__srot(a, r1, 'a');
		OP(pb);
		op__srot(a, r2, 'a');
		OP(pa);
	}
	ft_putstr("ss\nss\n");
	while(1);
}
