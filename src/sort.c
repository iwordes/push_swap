/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 15:25:31 by iwordes          ###   ########.fr       */
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

	s = *a;
	s.arr = MALT(int, a->len);
	ft_memcpy(s.arr, a->arr, sizeof(int) * a->len);

	ft_eprintf("\e[1;95mtry_sort\e[0;95m([", o);
	for (unsigned k = 0; k < s.len; k += 1)
		ft_eprintf("%s%d", (k > 0) ? ", " : "", s.arr[k]);
	ft_eprintf("]\e[1m<\e[0;95m, % i)", o);

	if (o < 0)
		while (o++)
			op__rrot(&s);
	else
		while (o--)
			op__rot(&s);

	o = 0;
	n = S1;
	ft_printf(" (%i)", n);

	//op__rot(a);
	s.len -= 1;
	/*if (n == s.min || n == s.max)
	{
		ft_eprintf(" |\e[91mM\e[95m|\n");
		free(s.arr);
		return (0);
	}*/
	while ((UINT)o < s.len && (S[0] < n || n < S1))
	{
		op__rot(&s);
		o += 1;
	}
	ft_eprintf(" -> %u\e[0m\n", o);
	free(s.arr);
	return (/*o >= H2(a->len) ? a->len - o : */o);
}

static void	do_sort(t_stack *a, t_stack *b, int o, int to)
{
	ft_eprintf("\e[93mdo_sort(%i, %i)\e[0m\n", o, to);
	if (to > 5 || to < -5)
	{
		ft_eprintf("\e[91m>> ERROR <<\e[0m\n");
		exit(1);
	}
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
#define SHORTER (ABS(o) + ABS(cache) < ABS(fo) + ABS(sh))

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
	fo = INT_MIN;
	sh = INT_MIN;
	while ((UINT)ABS(o) <= a->len / 2)
	{
		cache = try_sort(a, o);
		if (NEED_MOVE && SHORTER)
		{
			ft_eprintf("SET (%u, %i)\n", o, cache);
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
}
