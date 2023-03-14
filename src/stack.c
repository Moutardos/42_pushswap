/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:08 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/10 18:55:02 by lcozdenm         ###   ########.fr       */
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
		add_stack(&stack, data[size - i - 1]);
		i++;
	}
	return (stack);
}

t_stack	*add_stack(t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	if (*stack)
	{
		tmp = *stack;
		new->next = tmp;
		new->prev = tmp->prev;
		new->prev->next = new;
		(*stack)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
	}
	*stack = new;
	return (new);
}

void	del_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	*stack = (*stack)->next;
	if (*stack == tmp)
	{
		free(tmp);
		*stack = NULL;
	}
	else
		free(tmp);
}

void	free_stack(t_stack **stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		i++;
		del_stack(stack);
	}
}

void	swap_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->prev->next = (*stack);
	(*stack)->prev = tmp->prev;
	tmp->next = (*stack)->next;
	tmp->prev = (*stack);
	(*stack)->next->prev = tmp;
	(*stack)->next = tmp;
}
