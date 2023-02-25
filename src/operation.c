/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:30:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/25 17:57:29 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static int do_operation2(t_env *env, t_operation op)
{
	if (op == RRA)
	{
		do_operation(env, RA);
		reverse_stack(&env->st_a, env->s_a);
		return (0);
	}
	if (op == RRB)
	{
		do_operation(env, RB);
		reverse_stack(&env->st_b, env->s_b);
		return (0);
	}
	if (op == RRR)
	{
		do_operation(env, RR);
		reverse_stack(&env->st_a, env->s_a);
		reverse_stack(&env->st_b, env->s_b);
		return (0);
	}
	return (-2);
}

int	do_operation(t_env *env, t_operation op)
{
	if (!add_stack(&env->st_op, op))
		return(-1);
	env->size_op++;
	if (op == SA)
		return (swap_stack(&env->st_a), 0);
	if (op == SB)
		return(swap_stack(&env->st_b), 0);
	if (op == SS)
		return (do_operation(env, SA), do_operation(env, SB), 0);
	if (op == PA)
		return (env->s_a++, env->s_b--, push_stack(&env->st_a, &env->st_b), 0);
	if (op == PB)
		return (env->s_b++, env->s_a--, push_stack(&env->st_b, &env->st_a), 0);
	if (op == RA)
		return (rotate_stack(&env->st_a, env->s_a), 0);
	if (op == RB)
		return (rotate_stack(&env->st_b, env->s_b), 0);
	if (op == RR)
		return (do_operation(env, RA), do_operation(env, RB), 0);
	else
		return (do_operation2(env, op));
}

void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	add_stack(stack_a, (*stack_b)->data);
	del_stack(stack_b);
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

void	rotate_stack(t_stack **stack, int size)
{
	
}