/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:08 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/22 12:59:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(int *data, int size)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		add_stack(&stack, data[i]);
		i++;
	}
	return (stack);
}

//pile TODO
t_stack	*add_stack(t_stack **stack, int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = *stack;
	new->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack);
	(*stack)->prev = new;
	*stack = new;
	return (new);
}

void	del_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
}

void 	free_stack(t_stack **stack)
{
	while (*stack)
		del_stack(stack);
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
	ft_printf("%d ", tmp->data);
}