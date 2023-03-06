/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:53:38 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 15:40:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

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
		ft_printf("Empty stack\n");
	else if (is_op)
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
			tmp = tmp->next;
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

t_bool	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
