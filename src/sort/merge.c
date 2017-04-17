/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:29:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 13:11:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A1 a->arr[a->len - 1]
#define B1 b->arr[b->len - 1]

#define OP(O) op__(#O, op_##O, a, b)

void	merge(t_stack *a, t_stack *b)
{
	// 1. Align both stacks.
	op__srot(a, check_asc(a), 'a');
	op__srot(b, check_asc(b), 'b');

	// 2. B => A
	while (b->len)
	{
		if (B1 < A1 || (a->arr[0] == a->max && B1 > a->max))
			OP(pa);
		OP(ra);
	}

	// 3. Align A.
	op__srot(a, check_asc(a), 'a');
}
