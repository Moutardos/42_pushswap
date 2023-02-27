/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:53:38 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/27 19:41:36 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

int	*bsort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!array || size < 2)
		return (array);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	*pre_sort(int *array, int size)
{
	int *sorted;
	int *new;
	int i;
	int j;
	
	sorted = malloc(size * sizeof(int));
	sorted = ft_memcpy(sorted, array, size * sizeof(int));
	sorted = bsort(sorted, size);
	new = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] == sorted[i])
			{
				new[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (new);
}
char	*op_to_str(t_operation op)
{
	if (op == SA)
		return ("sa");
	if (op == SB)
		return ("sb");
	if (op == PA)
		return ("pa");
	if (op == PB)
		return ("pb");
	if (op == RA)
		return ("ra");
	if (op == RB)
		return ("rb");
	if (op == RR)
		return ("rr");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	else
		return ("NONE");
}

void	print_stack(t_stack *stack, t_bool is_op)
{
	t_stack	*tmp;

	if (!stack)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	if (is_op)
	{
		tmp = stack->prev;
		while (tmp != stack)
		{
			ft_printf("%s\n", op_to_str(tmp->data));
			tmp = tmp->prev;
		}
		ft_printf("%s\n", op_to_str(tmp->data));
	}
	else
	{	
		tmp = stack;
		while (tmp->next != stack)
		{
				ft_printf("%d ", tmp->data);
		}
		ft_printf("%d\n", tmp->data);
	}
}

int	get_bmax(int *array, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (ft_bitsize(max));
}

