/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:38:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/30 18:39:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define A a->arr[a->len - i - 1]
#define B b->arr[b->len - i - 1]

void	show(t_stack *a, t_stack *b)
{
	int		i;

	ft_putstr("\e[91mA[");
	i = 0;
	while (i < a->len)
	{
		ft_printf("%s%d", (i > 0) ? ", " : "", A);
		i += 1;
	}
	ft_putstr("]\n");
	ft_putstr("\e[94mB[");
	i = 0;
	while (i < b->len)
	{
		ft_printf("%s%d", (i > 0) ? ", " : "", B);
		i += 1;
	}
	ft_putstr("]\e[0m\n\n");
}
