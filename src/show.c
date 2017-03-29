/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:38:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 13:09:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	show(t_stack *a, t_stack *b)
{
	UINT	i;

	ft_putstr("\e[91mA[");
	i = 0;
	while (i < a->len)
	{
		ft_printf("%s%d", (i > 0) ? ", " : "", a->arr[i]);
		i += 1;
	}
	ft_putstr("] <=\n");
	ft_putstr("\e[94mB[");
	i = 0;
	while (i < b->len)
	{
		ft_printf("%s%d", (i > 0) ? ", " : "", b->arr[i]);
		i += 1;
	}
	ft_putstr("] <=\e[0m\n\n");
}
