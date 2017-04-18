/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _swap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:07:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 17:25:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s->arr
#define S1 S[s->len - 1]
#define S2 S[s->len - 2]

void	op__swap(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = S1;
	S1 = S2;
	S2 = tmp;
}
