/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 03:30:59 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/18 23:06:00 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <fcntl.h>

typedef enum	e_bool
{
	false,
	true,
}				t_bool;

enum			e_ops
{
	e_ops_sa,
	e_ops_sb,
	e_ops_ss,
	e_ops_pa,
	e_ops_pb,
	e_ops_ra,
	e_ops_rb,
	e_ops_rr,
	e_ops_rra,
	e_ops_rrb,
	e_ops_rrr,
};

typedef struct	s_arr
{
	int obj;
	int currentpos;
	int finalpos;
}				t_arr;

typedef	struct	s_pending
{
	char				*move;
	struct s_pending	*next;
}				t_pending;

typedef	struct	s_stack
{
	t_arr		*arr;
	int			len;
	t_pending	*pending;
}				t_stack;

static void	strto_stack(char **S_stack, t_stack *stack, int argc);
void		exec_ops(t_stack *stacka, t_stack *stackb, char *op);
void		ft_p(t_stack *stack, t_arr to_push);
void		ft_rr(t_stack *stack);
void		ft_r(t_stack *stack);
void		ft_s(t_stack *stack);
int			check_fsorted(t_stack stack);
void		check_dup_digits(t_stack stack);
int			check_stack_content(char **stack, int argc);
char		*getter(void);
void		error(void);
void		print_stack(t_stack stacka, t_stack stackb);
#endif
