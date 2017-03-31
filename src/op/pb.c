/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:40:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 19:51:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define B b->arr
#define A1 a->arr[a->len - 1]

void	op_pb(t_stack *a, t_stack *b)
{
	B[b->len] = A1;
	b->len += 1;
	a->len -= 1;
	minmax(a);
	minmax(b);
}
