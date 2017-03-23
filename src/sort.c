/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:00:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/22 17:29:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Sort Mk.I: Bubble (Basic Sort)
*/

#define A a->arr
#define B b->arr

#define A1 A[a->len - 1]
#define A2 A[a->len - 2]

void	sort(t_stack *a, t_stack *b)
{
	if (a->len < 2)
		return ;
	while (!check(a, b))
	{
		while (A1 <= A2)
		{
			op_ra(a, b);
			ft_putstr("ra\n");
		}
		while (A1 > A2)
		{
			op_sa(a, b);
			op_rra(a, b);
			ft_putstr("sa\nrra\n");
		}
	}
}
