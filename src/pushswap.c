/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:36:36 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/25 17:13:02 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

t_env *init_env(int *array, int size)
{
	t_env *env;

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

t_env	*sort_one(t_env *env, int offset)
{
	int		i;

	if (!env || offset < 0)
		return (NULL);
	i = 0;
	while (i < env->s_a)
	{
		if (env->st_a->data >> offset & 1)
			do_operation(env, RA);
		else
			do_operation(env, PB);
		i++;
	}
}

