/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:13:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/28 16:48:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define S s.arr
#define S1 S[s.len - 1]
#define S2 S[s.len - 2]

/*
** Checks if stack A is sorted (and if so, notes the sort offset)
*/

int		check_ps(t_stack *a)
{
	t_stack	s;
	UINT	i;
	int		o;

	o = 0;
	s = *a;
	while (S1 <= S2 && (UINT)o < a->len)
	{
		op__rot(&s);
		o += 1;
	}
	o += 1;
	if ((UINT)o >= s.len)
		o %= s.len;
	if ((UINT)o >= H2(s.len))
		o -= s.len;
	i = s.len - 1;
	while (i--)
	{
		op__rot(&s);
		if (S1 > S2)
			return (INT_MIN);
	}
	return (o);
}
