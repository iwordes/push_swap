/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 17:33:05 by iwordes          ###   ########.fr       */
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

static int	try_sort(t_stack *a, int o)
{
	t_stack	s;
	int		n;

	stk_cpy(&s, a);

	ft_eprintf("\e[1;95mtry_sort\e[0;95m[% i]", o);

	if (o < 0)
		while (o++)
			op__rrot(&s);
	else
		while (o--)
			op__rot(&s);

	o = 0;
	n = S1;
	s.len -= 1;
	ft_printf(" (%i)", n);
	if (n == s.min || n == s.max)
	{
		ft_eprintf(" |\e[91mM\e[95m|\n");
		free(s.arr);
		return (0);
	}
	// TODO: Better constraint.
	while (S[0] > n || n > S1)
	{
		op__rot(&s);
		o += 1;
	}
	ft_eprintf(" -> %u\e[0m\n", o);
	free(s.arr);
	return (/*(UINT)o >= H2(s.len) ? s.len - o : */o);
}

static void	do_sort(t_stack *a, t_stack *b, int o, int to)
{
	ft_eprintf("\e[93mdo_sort(%i, %i)\e[0m\n", o, to);
	/*if (to > 5 || to < -5)
	{
		ft_eprintf("\e[91m>> ERROR <<\e[0m\n");
		exit(1);
	}*/
	if (o >= 0)
		while (o--)
			OP(ra);
	else
		while (o++)
			OP(rra);
	OP(pb);
	if (to >= 0)
		while (to--)
			OP(ra);
	else
		while (to++)
			OP(rra);
	OP(pa);
}

#define NEED_MOVE (cache != 0)
#define SHORTER ((UINT)(ABS(o) + ABS(cache)) < (UINT)(ABS(fo) + ABS(sh)))

static void	find_sort(t_stack *a, t_stack *b)
{
	int		o;
	int		fo;
	int		sh;
	int		cache;

	ft_eprintf("\e[92mfind_sort([");
	for (unsigned k = 0; k < a->len; k += 1)
		ft_eprintf("%s%d", (k > 0) ? ", " : "", a->arr[k]);
	ft_eprintf("])\e[0m\n");

	o = 0;
	fo = INT_MAX;
	sh = INT_MAX;
	// TODO: Make this condition work optimally on both even and odd stacks
	while ((UINT)ABS(o) <= a->len / 2)
	{
		cache = try_sort(a, o);
		if (NEED_MOVE && SHORTER)
		{

			ft_eprintf("SET (%i, %i)\n", o, cache);

			sh = cache;
			fo = o;
		}
		o = (o < 0) ? -o : -(o + 1);
	}

	ft_eprintf("\e[93mfinal: o = %i, fo = %i\e[0m\n", o, fo);

	do_sort(a, b, fo, sh);
}

void		sort(t_stack *a, t_stack *b)
{
	int		o;

	while ((o = check_ps(a)) == INT_MIN)
		find_sort(a, b);
	if (o < 0)
		while (o++)
			OP(rra);
	else
		while (o--)
			OP(ra);

	ft_eprintf("\e[92m[");
	for (unsigned k = a->len - 1; k; k--)
		ft_eprintf("%s%d", (k != a->len - 1) ? ", " : "", a->arr[k]);
	ft_eprintf("]\e[0m\n");
}
