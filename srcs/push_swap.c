/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:43:16 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/18 22:46:50 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

// 11    22 33 [9]  7 1 5 
  //11 12 10  10 10 11 7   7 10 11  

#include <stdlib.h>
#include <stdio.h>

void			quick_sort(int *tab, int start, int end)
{
	int pivot;
	int i;
	int j;
	int tmp;

	if (start >= end)
		return ;
	i = start;
	j = start + 1;
	pivot = start;
	while (j <= end)
	{
		if (tab[pivot] > tab[j])
		{
			i++;
			tmp = tab[j];
			tab[j] = tab[i];
			tab[i] = tmp; 
		}
		j++;
	}
	tmp = tab[pivot];
	tab[pivot] = tab[i];
	tab[i] = tmp;
	quick_sort(tab, 0, i - 1);
	quick_sort(tab, i + 1, end);
}

int		main()
{
	int *tab;
	int i = 0;

	tab = malloc(sizeof(int) * 7);
	tab[0] = 11;
	tab[1] = 17;
	tab[2] = 1;
	tab[3] = 100;
	tab[4] = 55;
	tab[5] = 99;
	tab[6] = 6;
	tab[7] = 6;
	tab[8] = 6;
	tab[9] = 0;
	tab[10] = 5000;
	quick_sort(tab, 0, 10);
	while (i < 11)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

/*void			ft_quick_sort(t_stack *stacka, t_stack *stackb)
{
	int			i;
	int			pivot;
	t_pending	pending;

	i = 0;
	pivot = stacka->len - 1;
	while (i < pivot)
	{
		
		if (stacka->arr[i] < stacka->arr[pivot])
		{
			exec_ops(stacka, stackb, "pb");
			pivot = stacka->len - 1;
			
		}
		else
		{
			exec_ops(stacka, stackb, "ra");
		}
	}
}

int 			main (int argc, char **argv)
{
	t_stack	stacka;
	t_stack stackb;
	char	*line;

	strto_stack(argv, &stacka, argc);
	stackb.arr = (int*)malloc(sizeof(int) * stacka.len);
	stackb.len = 0;
	check_dup_digits(stacka);
	ft_quick_sort()
	free(stacka.arr);
	free(stackb.arr);
	return (0);
}*/
