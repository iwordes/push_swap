/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:13:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/28 16:45:28 by iwordes          ###   ########.fr       */
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

	ft_eprintf("\e[91mcheck_ps\e[0m\n");
	o = 0;
	s = *a;
	while (S1 <= S2 && (UINT)o < a->len)
	{
		ft_eprintf("\e[92ms1: %d\ns2: %d\n", S1, S2);
		op__rot(&s);
		ft_eprintf("\e[93ms1: %d\ns2: %d\e[0m\n--\n", S1, S2);
		o += 1;
	}
	o += 1;
	ft_eprintf("\e[93mo: %u (s.len: %u)\n", o, s.len);
	if ((UINT)o >= s.len)
		o %= s.len;
	ft_eprintf("o: %u\n", o);
	if ((UINT)o >= H2(s.len))
		o -= s.len;
	ft_eprintf("o: %u\e[0m\n", o);
	i = s.len - 1;
	while (i--)
	{
		op__rot(&s);
		if (S1 > S2)
			return (INT_MIN);
	}
	ft_eprintf("\e[91mSORTED\e[0m\n");
	return (o);
}
