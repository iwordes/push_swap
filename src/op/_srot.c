/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _srot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:43:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 15:49:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	op__srot(t_stack *s, int o, bool verbose)
{
	//o %= s->len;
	//(o - s->len >= s->len / 2) && (o -= s->len);
	if (o < 0)
		while (o++)
		{
			if (verbose)
				ft_putstr("rrot\n");
			op__rrot(s);
		}
	else
		while (o--)
		{
			if (verbose)
				ft_putstr("rot\n");
			op__rot(s);
		}
}
