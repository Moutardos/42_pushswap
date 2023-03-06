/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:30:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 15:47:14 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static int	do_operation2(t_env *env, t_operation op)
{
	int	i;

	if (op == RRA)
		return (rotate_stack(&env->st_a, TRUE), 0);
	if (op == RRB)
		return (rotate_stack(&env->st_b, TRUE), 0);
	if (op == RRR)
	{
		do_operation(env, RRA);
		do_operation(env, RRB);
		return (0);
	}
	return (op);
}

int	do_operation(t_env *env, t_operation op)
{
	if (!add_stack(&env->st_op, op))
		return (-1);
	env->size_op++;
	if (op == SA)
		return (swap_stack(&env->st_a), 0);
	if (op == SB)
		return (swap_stack(&env->st_b), 0);
	if (op == SS)
		return (do_operation(env, SA), do_operation(env, SB), 0);
	if (op == PA)
		return (env->s_a++, env->s_b--, push_stack(&env->st_a, &env->st_b), 0);
	if (op == PB)
		return (env->s_b++, env->s_a--, push_stack(&env->st_b, &env->st_a), 0);
	if (op == RA)
		return (rotate_stack(&env->st_a, FALSE), 0);
	if (op == RB)
		return (rotate_stack(&env->st_b, FALSE), 0);
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

void	rotate_stack(t_stack **stack, t_bool reverse)
{
	t_stack	*tmp;
	t_stack	*first;
	int		first_data;

	if (!stack || !*stack)
		return ;
	first = *stack;
	first_data = first->data;
	tmp = *stack;
	if (!reverse)
	{
		while (tmp->next != first)
		{
			tmp->data = tmp->next->data;
			tmp = tmp->next;
		}
		tmp->data = first_data;
		return ;
	}
	while (tmp->prev != first)
	{
		tmp->data = tmp->prev->data;
		tmp = tmp->prev;
	}
	tmp->data = first_data;
}

t_env	*lil_sort(t_env *env)
{
	t_stack	*st_1;
	t_stack	*st_2;

	st_1 = env->st_a;
	st_2 = st_1->next;
	while (!(st_1->data < st_2->data && st_2->data < st_2->next->data))
	{
		if (st_1->data > st_2->next->data)
		{
			if (st_1->data > st_2->data)
				do_operation(env, RA);
			else
				do_operation(env, RRA);
		}
		else if (st_1->data > st_2->data)
			do_operation(env, SA);
		else if (st_2->data > st_2->next->data)
		{
			do_operation(env, SA);
			do_operation(env, RA);
		}
		st_1 = env->st_a;
		st_2 = st_1->next;
	}
	return (env);
}
// a  ra rra
// 1  2   3
// 2  3   1
// 3  1   2