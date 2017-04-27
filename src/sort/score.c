/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:36:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/26 18:58:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

UINT	score(int ra, int rb)
{
	UINT	score;
	UINT	min;

	score = 0;
	if (ra > 0 && rb > 0)
	{
		min = MIN(ABS(ra), ABS(rb));
		score += min;
		ra -= min;
		rb -= min;
	}
	if (ra < 0 && rb < 0)
	{
		min = MIN(ABS(ra), ABS(rb));
		score += min;
		ra += min;
		rb += min;
	}
	score += ABS(ra);
	score += ABS(rb);
	return (score);
}
