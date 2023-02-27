/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:43:09 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/27 19:40:43 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

int main(int argc, char **argv)
{
	// TODO: code
	t_env	*env;
	int		bitsize;
	int		i;
	int		*original;
	int		*array;
	int		len;
	
	original = ft_strtoi(argv[1], &len);
	array = pre_sort(original, len);
	i = 0;
	while (i < len)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	env = init_env(array, len);
	if (!env)
		return (0);
	i = 0;
	bitsize = get_bmax(array, len);
	while (i < bitsize)
	{
		sort_one(env, i);
		i++;
	}
	print_stack(env->st_op, TRUE);
	free_env(env);
	return (0);
}
