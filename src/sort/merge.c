/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:29:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 15:42:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define BA a->arr[0]
#define TB b->arr[b->len - 1]

#define OP(O) op__(#O, op_##O, a, b)

void	merge(t_stack *a, t_stack *b)
{
	// 1. Align both stacks.
	op__srot(a, check_asc(a), 'a');
	op__srot(b, check_desc(b), 'b');

	// 2. B => A
	while (b->len && b->max > a->min)
		if (TB < BA)
			OP(rra);
		else
			OP(pa);

	// 3. Align A.
	op__srot(a, check_asc(a), 'a');

	while (b->len)
		OP(pa);
}

/*

1 6
3 5
7 2

rra

7 6
1 5
3 2

pa
pa

5
6
7
1
3 2

rra

3
5
6
7
1 2

pa

2
3
5
6
7
1

*/
