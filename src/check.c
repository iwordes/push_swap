/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:03:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 19:03:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define CURR a->arr[i]
#define PREV a->arr[i - 1]

bool	check(t_stack *a, t_stack *b)
{
	int		i;

	i = 1;
	while (i < a->len)
	{
		if (CURR > PREV)
			return (false);
		i += 1;
	}
	return (b->len == 0);
}
