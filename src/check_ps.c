/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:13:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 16:12:31 by iwordes          ###   ########.fr       */
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
	stk_cpy(&s, a);
	ft_eprintf("\e[93mCHECK: ");
	while (S1 <= S2 && (UINT)o < a->len)
	{
		op__rot(&s);
		o += 1;
	}
	op__rot(&s);
	o += 1;
	if ((UINT)o >= s.len)
		o %= s.len;
	if ((UINT)o >= H2(s.len))
		o -= s.len;
	i = 0;
	while (i + 1 < s.len)
	{
		if (S[i] < S[i + 1])
		{
			ft_eprintf("\e[91mUNSORTED\e[0m\n", o);
			break ;
		}
		i += 1;
	}
	free(s.arr);
	if (i + 1 == s.len)
		ft_eprintf("\e[92mSORTED\e[93m (%i)\e[0m\n", o);
	return ((i + 1 == s.len) ? o : INT_MIN);
}
