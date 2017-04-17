/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:44:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/04/17 11:00:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include <libarg.h>
# include <libft.h>

# define MGUARD(MEM) if ((MEM) == NULL) exit(12)
# define H2(N) ((N >> 1) + (N & 1))

# define ASSERT(C) if (!(C)) error();

typedef struct	s_stack
{
	int			*arr;
	int			min;
	int			max;
	int			len;
}				t_stack;

typedef struct	s_op
{
	char		*str;
	void		(*fn)(t_stack*, t_stack*);
}				t_op;

typedef struct	s_main
{
	unsigned	ops;
	int			show_ops;
	int			show_vis;
}				t_main;

t_main			g_mn;

void			arg_cnt(void);
void			arg_vis(void);

void			init(t_stack *a, t_stack *b, int argc, char **argv);
void			show(t_stack *a, t_stack *b, const char *op);

int				check_asc(t_stack *s);
int				check_desc(t_stack *s);

void			sort(t_stack *a, t_stack *b);

void			sort1(t_stack *a, t_stack *b);
void			sort2(t_stack *a, t_stack *b);
void			merge(t_stack *a, t_stack *b);

void			minmax(t_stack *s);

void			error(void);

#define OARGS void (*f)(t_stack*, t_stack*), t_stack *a, t_stack *b
void			op__(const char *s, OARGS);
void			op__rot(t_stack *s);
void			op__rrot(t_stack *s);
void			op__srot(t_stack *s, int o, char name);
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
