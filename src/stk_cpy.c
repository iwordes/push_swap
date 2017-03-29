/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:43:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 15:45:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stk_cpy(t_stack *dest, t_stack *src)
{
	*dest = *src;
	dest->arr = MALT(int, src->len);
	ft_memcpy(dest->arr, src->arr, sizeof(int) * src->len);
}
