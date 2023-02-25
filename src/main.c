/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:43:09 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/25 18:06:29 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

int main(int argc, char **argv)
{
	// TODO: code
	t_env	*env;
	int		array[3] = {1,2,3};

	env = init_env(array, 3);
	if (!env)
		return (0);
	print_stack(env->st_a);
	do_operation(env, PB);
	print_stack(env->st_a);
	print_stack(env->st_b);
	do_operation(env, PA);
	print_stack(env->st_a);
	return (0);
}