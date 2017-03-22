/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:44:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/22 16:10:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <libft.h>

# define UINT unsigned
# define MGUARD(MEM) if ((MEM) == NULL) exit(12)

typedef struct	s_stack
{
	int			*arr;
	size_t		len;
}				t_stack;

void			init(t_stack *a, t_stack *b, int argc, char **argv);
void			sort(t_stack *a, t_stack *b);
bool			check(t_stack *a, t_stack *b);

void			error(void);

void			op__rot(t_stack *s);
void			op__rrot(t_stack *s);
void			op__swap(t_stack *s);

void			op_pa(t_stack *a, t_stack *b);
void			op_pb(t_stack *a, t_stack *b);
void			op_ra(t_stack *a, t_stack *b);
void			op_rb(t_stack *a, t_stack *b);
void			op_rr(t_stack *a, t_stack *b);
void			op_rra(t_stack *a, t_stack *b);
void			op_rrb(t_stack *a, t_stack *b);
void			op_rrr(t_stack *a, t_stack *b);
void			op_sa(t_stack *a, t_stack *b);
void			op_sb(t_stack *a, t_stack *b);
void			op_ss(t_stack *a, t_stack *b);

#endif
