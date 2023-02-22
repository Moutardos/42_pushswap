/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:30:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/22 12:56:59 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

t_operation	str_to_operation(char *str)
{
	if (!ft_strcmp(str, "sa"))
		return ((t_operation) SA);
	if (!ft_strcmp(str, "sb"))
		return ((t_operation) SB);
	if (!ft_strcmp(str, "ss"))
		return ((t_operation) SB);
	if (!ft_strcmp(str, "pa"))
		return ((t_operation) PA);
	if (!ft_strcmp(str, "pb"))
		return ((t_operation) PB);
	if (!ft_strcmp(str, "ra"))
		return ((t_operation) RA);
	if (!ft_strcmp(str, "rb"))
		return ((t_operation) RB);
	if (!ft_strcmp(str, "rr"))
		return ((t_operation) RR);
	if (!ft_strcmp(str, "rra"))
		return ((t_operation) RRA);
	if (!ft_strcmp(str, "rrb"))
		return ((t_operation) RRB);
	if (!ft_strcmp(str, "rrr"))
		return ((t_operation) RRR);
	else
		return ((t_operation) NONE);
}

int	do_operation(t_env *env, t_operation op)
{
	if (op == SA)
		return (swap_stack(&env->stack_a), 0);
	if (op == SB)
		return(swap_stack(&env->stack_b), 0);
	if (op == SS)
		return (swap_stack(&env->stack_a), swap_stack(&env->stack_b), 0);
	if (op == PA)
		return (push_stack(&env->stack_a, &env->stack_b), 0);
	if (op == PB)
		return (push_stack(&env->stack_b, &env->stack_a), 0);
	if (op == RA)
		return (rotate_stack(&env->stack_a, env->size_a), 0);
	if (op == RB)
		return (rotate_stack(&env->stack_b, env->size_b), 0);
	if (op == RR)
		return (rotate_stack(&env->stack_a, env->size_a), rotate_stack(&env->stack_b, env->size_b), 0);
	if (op == RRA)
	{
		do_operation(env, RA);
		return (reverse_stack(&env->stack_a, env->size_a));
	}
	if (op == RRA)
	{
		do_operation(env, RB);
		return (reverse_stack(&env->stack_b, env->size_b), 0);
	}	
	if (op == RRR)
	{
		do_operation(env, RR);
		return (reverse_stack(&env->stack_a), reverse_stack(&env->stack_b), 0);
	}
	return (op);
}

t_stack	*swap_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

t_stack	*push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return (NULL);
	tmp = *stack_b;
	(*stack_b)->prev->next = (*stack_b)->next;
	(*stack_b)->next->prev = (*stack_b)->prev;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	tmp->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = tmp;
	(*stack_a)->prev = tmp;
	*stack_a = tmp;
}

void	reverse_stack(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack *tmp;
	
	if (!stack || !*stack || size < 2)
		return ;
	first = *stack;
	tmp = first->next;
	while ((*stack)->next != first)
		(*stack) = (*stack)->next;
	first->next->prev = (*stack);
	(*stack)->prev->next = first;
	first->next = (*stack);
	first->prev = (*stack)->prev;
	(*stack)->prev = first;
	(*stack)->next = tmp;
}