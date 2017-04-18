/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rrot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:52:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 17:24:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define S1 S[s->len - 1]

void	op__rrot(t_stack *s)
{
	int		i;
	int		tmp;

	if (s->len < 2)
		return ;
	tmp = S[0];
	i = 0;
	while (i + 1 < s->len)
	{
		S[i] = S[i + 1];
		i += 1;
	}
	S1 = tmp;
}
