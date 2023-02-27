/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:53:38 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/27 17:47:45 by lcozdenm         ###   ########.fr       */
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

char	*op_to_str(t_operation op)
{
	if (op == SA)
		return ("SA");
	if (op == SB)
		return ("SB");
	if (op == PA)
		return ("SA");
	if (op == PB)
		return ("PB");
	if (op == RA)
		return ("RA");
	if (op == RB)
		return ("RB");
	if (op == RR)
		return ("RR");
	if (op == RRA)
		return ("RRA");
	if (op == RRB)
		return ("RRB");
	if (op == RRR)
		return ("RRR");
	else
		return ("NONE");
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->data);
}
