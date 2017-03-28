/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:52:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/28 16:46:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define S1 S[s->len - 1]

void	op__rot(t_stack *s)
{
	UINT	i;
	int		tmp;

	ft_eprintf("\e[96mop_rot([");
	for (UINT I = 0; I < s->len; I += 1)
		ft_eprintf("%s%d", (I > 0) ? ", " : "", S[I]);
	ft_eprintf("])\n{\n");

	tmp = S1;
	i = s->len - 1;
	ft_eprintf("    bak [%u]\n", i);
	while (i)
	{
		ft_eprintf("    cpy [%u] -> [%u]\n", i - 1, i);
		S[i] = S[i - 1];
		i -= 1;
	}
	S[0] = tmp;
	ft_eprintf("    ins [%u]\n", 0);
	ft_eprintf("}\e[0m\n");
}
