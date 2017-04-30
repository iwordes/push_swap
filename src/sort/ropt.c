/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:02:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/29 20:51:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define OH2(I, S) ((I % S->len) > S->len / 2)
#define OPT(I, S) ((I % S->len) - (OH2(I, S) ? S->len : 0))

void	ropt(int *ra, int *rb, t_stack *a, t_stack *b)
{
	int		ra_pos;
	int		rb_pos;
	int		ra_neg;
	int		rb_neg;

	*ra %= a->len;
	*rb %= b->len;
	ra_pos = *ra;
	rb_pos = *rb;
	ra_neg = *ra - a->len;
	rb_neg = *rb - b->len;
	if (score(*ra, *rb) > score(ra_pos, rb_neg))
		*rb = rb_neg;
	if (score(*ra, *rb) > score(ra_neg, rb_pos))
	{
		*ra = ra_neg;
		*rb = rb_pos;
	}
	if (score(*ra, *rb) > score(ra_neg, rb_neg))
	{
		*ra = ra_neg;
		*rb = rb_neg;
	}
}
