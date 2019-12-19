/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:17:02 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/18 23:02:38 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//[1 2 3 4]
//checker 3 2 4 5
/*
 * S_digit is a string that supposed to containg only digits ascci values
 * */

#include "push_swap.h"

void		error(void)
{
	ft_printf(2, "exited 1\n");
	exit(1);
}

char		*getter(void)
{
	char	*line;
	char	buff[2];
	char	*strtmp;
	int		t;

	if (!(line = (char*)ft_memalloc(1)))
		error();
	while ((t = read(0, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (!(strtmp = ft_strjoin(line, buff)))
			error();
		ft_memdel((void**)&line);
		line = strtmp;
		if (buff[0] == '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			return (line);
		}
	}
	if (t < 0)
		error();
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

int			check_stack_content(char **stack, int argc)
{
	int		i;
	int		j;
	int		len;
	t_bool	new_dig;

	i = 1;
	len = 0;
	while (i < argc)
	{
		new_dig = true;
		j = 0;
		while (stack[i][j] != '\0')
		{
			if (ft_isdigit(stack[i][j]))
			{
				if (new_dig)
				{
					new_dig = false;
					len++;
				}
			}
			else if (stack[i][j] == ' ' || stack[i][j] == '\t')
				new_dig = true;
			else
			{
				ft_printf(1, "Only digits permited\n");
				error();
			}
			j++;
		}
		i++;
	}
	return (len);
}

void		check_dup_digits(t_stack stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack.len)
	{
		j = i + 1;
		while (j < stack.len)
		{
			if (stack.arr[i].obj == stack.arr[j].obj)
			{
				ft_printf(1, "Digit duplication forbidden\n");
				error();
			}
			j++;
		}
		i++;
	}
}

int			check_fsorted(t_stack stack)
{
	int i;
	int tmp;

	i = 0;
	while (i < stack.len - 1)
	{
		if (stack.arr[i].obj > stack.arr[i + 1].obj)
			return (0);
		i++;
	}
	return (1);
}

void		ft_r(t_stack *stack)
{
	int i;
	t_arr tmp0;
	t_arr tmp1;

	if (!stack->len)
		return ;
	i = stack->len - 2;
	tmp0 = stack->arr[stack->len - 1];
	while ( i >= 0)
	{
		tmp1 = stack->arr[i];
		stack->arr[i] = tmp0;
		tmp0 = tmp1;
		i--;
	}
	stack->arr[stack->len - 1] = tmp0;
}

void		ft_rr(t_stack *stack)
{
	int i;
	t_arr tmp0;
	t_arr tmp1;

	if (!stack->len)
		return ;
	i = 1;
	tmp0 = stack->arr[0];
	while (i < stack->len)
	{
		tmp1 = stack->arr[i];
		stack->arr[i] = tmp0;
		tmp0 = tmp1;
		i++;
	}
	stack->arr[0] = tmp0;
}

void		ft_p(t_stack *stack, t_arr to_push)
{
	int i;
	t_arr tmp0;
	t_arr tmp1;

	if (!stack->len)
	{
		stack->arr[0] = to_push;
		stack->len++;
		return ;
	}
	i = 1;
	tmp0 = stack->arr[0];
	while (i < stack->len)
	{
		tmp1 = stack->arr[i];
		stack->arr[i] = tmp0;
		tmp0 = tmp1;
		i++;
	}	
	stack->arr[i] = tmp0;
	stack->arr[0] = to_push;
	stack->len++;
}

void		ft_s(t_stack *stack)
{
	t_arr tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
}

void		print_stack(t_stack stacka, t_stack stackb)
{
	int i;

	i = 0;
	ft_printf(1, "this is stack A:\n");
	while (i < stacka.len)
	{
		ft_printf(1, "%d\n", stacka.arr[i]);
		i++;
	}

	i = 0;
	ft_printf(1, "this is stack B:\n");
	while (i < stackb.len)
	{
		ft_printf(1, "%d\n", stackb.arr[i]);
		i++;
	}

}

void		exec_ops(t_stack *stacka, t_stack *stackb, char *op)
{
	ft_printf(1, "op is |%s|\n", op);
	if (!ft_strcmp(op, "sa"))
		ft_s(stacka);
	else if (!ft_strcmp(op, "sb"))
		ft_s(stackb);
	else if (!ft_strcmp(op, "ss"))
	{
		ft_s(stacka);
		ft_s(stackb);
	}
	else if (!ft_strcmp(op, "pa"))
	{
		if (stackb->len > 0)
		{
			ft_p(stacka, stackb->arr[0]);
			ft_r(stackb);
			stackb->len--;
		}
	}
	else if (!ft_strcmp(op, "pb"))
	{
		if (stacka->len > 0)
		{
			ft_p(stackb, stacka->arr[0]);
			ft_r(stacka);
			stacka->len--;
		}
	}
	else if (!ft_strcmp(op, "ra"))
		ft_r(stacka);
	else if (!ft_strcmp(op, "rb"))
		ft_r(stackb);
	else if (!ft_strcmp(op, "rr"))
	{
		ft_r(stacka);
		ft_r(stackb);
	}
	else if (!ft_strcmp(op, "rra"))
		ft_rr(stacka);
	else if (!ft_strcmp(op, "rrb"))
		ft_rr(stackb);
	else if (!ft_strcmp(op, "rrr"))
	{
		ft_rr(stacka);
		ft_rr(stackb);
	}
	else
	{
		ft_printf(1, "op error\n");
		error();
	}
	print_stack(*stacka, *stackb);
}

static void	strto_stack(char **S_stack, t_stack *stack, int argc)
{
	int i;
	int j;
	int k;
	int len;

	i = 1;
	k = 0;
	stack->len = check_stack_content(S_stack, argc);
	ft_printf(1, "%d\n", stack->len);
	if (stack->len == 0)
	{
		ft_printf(1, "Stack is empty\n");
		error();
	}
	stack->arr = (t_arr*)malloc(sizeof(t_arr) * stack->len);
	while (i < argc)
	{
		j = 0;
		while (S_stack[i][j] == ' ' || S_stack[i][j] == '\t')
			j++;
		while (S_stack[i][j] != '\0')
		{
			stack->arr[k].obj = ft_atoi(S_stack[i] + j);
			stack->arr[k].currentpos = k;
			k++;
			while (S_stack[i][j] == ' ' || S_stack[i][j] == '\t')
				j++;
			while (ft_isdigit(S_stack[i][j]))
				j++;
		}
		i++;
	}
	print_stack(*stack, *stack);
}

int 			main (int argc, char **argv)
{
	t_stack	stacka;
	t_stack stackb;
	char	*line;

	strto_stack(argv, &stacka, argc);
	stackb.arr = (t_arr*)malloc(sizeof(t_arr) * stacka.len);
	stackb.len = 0;
	check_dup_digits(stacka);
	while ((line = getter()))
	{
		exec_ops(&stacka, &stackb, line);
		free(line);
	}
	if (check_fsorted(stacka))
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free(stacka.arr);
	free(stackb.arr);
	return (0);
}
