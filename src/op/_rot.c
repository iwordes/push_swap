/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:52:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 17:24:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define S1 S[s->len - 1]

void	op__rot(t_stack *s)
{
	UINT	i;
	int		tmp;

	if (s->len < 2)
		return ;
	tmp = S1;
	i = s->len - 1;
	while (i)
	{
		S[i] = S[i - 1];
		i -= 1;
	}
	S[0] = tmp;
}
