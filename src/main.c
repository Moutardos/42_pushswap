/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:43:09 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/28 15:18:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"
#include "parsing.h"
int main(int argc, char **argv)
{
	// TODO: code
	t_env	*env;
	int		bitsize;
	int		i;
	int		*original;
	int		*array;
	int		len;
	
	//original = ft_strtoi(argv[1], &len);
	original = transform_array(argv + 1, argc - 1, &len);
	array = pre_sort(original, len);
	i = 0;
	if (!array)
		return (0);
	env = init_env(array, len);
	if (!env)
		return (free(array), 0);
	i = 0;
	bitsize = get_bmax(array, len);
	while (i < bitsize)
	{
		sort_one(env, i);
		i++;
	}
	free(array);
	print_stack(env->st_op, TRUE);
	free_env(env);
	return (0);
}
