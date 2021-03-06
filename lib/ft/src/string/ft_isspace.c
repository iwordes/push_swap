/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:14:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\t'
	|| c == '\r' || c == '\n'
	|| c == '\f' || c == '\v');
}
