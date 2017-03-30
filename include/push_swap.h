/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:44:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/29 19:01:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <libft.h>

# define UINT unsigned
# define MGUARD(MEM) if ((MEM) == NULL) exit(12)
# define H2(N) (N / 2 + (N & 1))

typedef struct	s_stack
{
	int			*arr;
	int			min;
	int			max;
	int			len;
}				t_stack;

void			init(t_stack *a, t_stack *b, int argc, char **argv);
void			sort(t_stack *a, t_stack *b);
void			show(t_stack *a, t_stack *b);
bool			check(t_stack *a, t_stack *b);
int				check_ps(t_stack *a);

void			stk_cpy(t_stack *dest, t_stack *src);

void			error(void);

#define OARGS void (*f)(t_stack*, t_stack*), t_stack *a, t_stack *b
void			op__(const char *s, OARGS);
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
