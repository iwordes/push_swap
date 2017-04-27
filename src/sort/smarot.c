/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smarot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:36:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/26 18:37:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	smarot(t_stack *a, t_stack *b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		OP(rr);
		ra -= 1;
		rb -= 1;
	}
	while (ra < 0 && rb < 0)
	{
		OP(rrr);
		ra += 1;
		rb += 1;
	}
	op__srot(a, ra, 'a');
	op__srot(b, rb, 'b');
}
