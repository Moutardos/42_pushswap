/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:43:09 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/10 18:50:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	int		*original;
	int		*array;
	int		len;

	original = transform_array(argv + 1, argc - 1, &len);
	if (!original)
		return (ft_printf("Error\n"), 0);
	if (verification(original, len) == -1)
		return (free(original), ft_printf("Error\n"), 0);
	if (!verification(original, len))
		return (free(original), 0);
	array = pre_sort(original, len);
	free(original);
	if (!array)
		return (0);
	env = init_env(array, len);
	if (!env)
		return (free(array), 0);
	loic_sort(env, get_bmax(array, len));
	free(array);
	print_stack(env->st_op, TRUE);
	free_env(env);
	return (0);
}
