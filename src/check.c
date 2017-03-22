/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:03:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/22 15:41:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define CURR a->arr[i]
#define PREV a->arr[i - 1]

bool	check(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 1;
	while (i < a->len)
	{
		if (PREV < CURR)
			return (false);
		i += 1;
	}
	return (b->len == 0);
}
