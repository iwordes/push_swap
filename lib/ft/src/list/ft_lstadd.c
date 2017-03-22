/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:53 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list** list and a t_list* link, prepends the given link to the
** beginning of the list.
** - If the given list or link is NULL, does nothing.
*/

void	ft_lstadd(t_list **list, t_list *link)
{
	ft_lstunshift(list, link);
}
