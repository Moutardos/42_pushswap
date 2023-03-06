/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:36:36 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 15:52:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

t_env	*init_env(int *array, int size)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->st_a = new_stack(array, size);
	if (!env->st_a)
		return (free(env), NULL);
	env->st_b = NULL;
	env->s_a = size;
	env->s_b = 0;
	env->st_op = NULL;
	env->size_op = 0;
	return (env);
}

void	free_env(t_env *env)
{
	free_stack(&env->st_a, env->s_a);
	free_stack(&env->st_b, env->s_b);
	free_stack(&env->st_op, env->size_op);
	free(env);
}

t_env	*radix(t_env *env, int offset)
{
	int		i;
	int		size;

	if (!env || offset < 0)
		return (NULL);
	i = 0;
	size = env->s_a;
	while (i < size)
	{
		if (env->st_a->data >> offset & 1)
			do_operation(env, RA);
		else
			do_operation(env, PB);
		i++;
	}
	i = 0;
	size = env->s_b;
	while (i < size)
	{
		do_operation(env, PA);
		i++;
	}
	return (env);
}

t_env	*five_sort(t_env *env)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (env->st_a->data != 3 && env->st_a->data != 4)
			do_operation(env, RA);
		do_operation(env, PB);
		i++;
	}
	if (env->st_b->data < env->st_b->next->data)
		do_operation(env, SB);
	lil_sort(env);
	do_operation(env, PA);
	do_operation(env, PA);
	do_operation(env, RA);
	do_operation(env, RA);
	return (env);
}

t_env	*loic_sort(t_env *env, int bitsize)
{
	int	i;

	if (!env)
		return (NULL);
	i = 0;
	if (env->s_a == 2)
		do_operation(env, SA);
	else if (env->s_a == 5)
		five_sort(env);
	else if (env->s_a == 3)
		lil_sort(env);
	else
	{
		while (i < bitsize)
			radix(env, i);
		i++;
	}
	return (env);
}
