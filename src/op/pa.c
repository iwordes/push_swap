/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:35:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 17:23:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr
#define B1 b->arr[b->len - 1]

void	op_pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	A[a->len] = B1;
	a->len += 1;
	b->len -= 1;
	minmax(a);
	minmax(b);
}
