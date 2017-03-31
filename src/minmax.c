/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:28:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 19:34:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr

void	minmax(t_stack *s)
{
	int		i;

	i = 0;
	s->min = INT_MAX;
	s->max = INT_MIN;
	while (i < s->len)
	{
		if (s->min > S[i])
			s->min = S[i];
		if (s->max < S[i])
			s->max = S[i];
		i += 1;
	}
}
