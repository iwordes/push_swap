/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:29:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 15:44:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define BA a->arr[0]
#define TB b->arr[b->len - 1]

#define OP(O) op__(#O, op_##O, a, b)

void	merge(t_stack *a, t_stack *b)
{
	op__srot(a, check_asc(a), 'a');
	op__srot(b, check_desc(b), 'b');
	while (b->len && b->max > a->min)
		if (TB < BA)
			OP(rra);
		else
			OP(pa);
	op__srot(a, check_asc(a), 'a');
	while (b->len)
		OP(pa);
}
