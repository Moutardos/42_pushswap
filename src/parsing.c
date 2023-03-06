/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:24:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 12:50:03 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	*bsort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!array || size < 2)
		return (array);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	*pre_sort(int *array, int size)
{
	int	*sorted;
	int	*new;
	int	pos[2];

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	sorted = bsort(ft_memcpy(sorted, array, size * sizeof(int)), size);
	new = malloc(size * sizeof(int));
	if (!new)
		return (free(sorted), NULL);
	pos[0] = -1;
	while (++pos[0] < size)
	{
		pos[1] = -1;
		while (++pos[1] < size)
		{
			if (array[pos[1]] == sorted[pos[0]])
			{
				new[pos[1]] = pos[0];
				break ;
			}
		}
	}
	return (new);
}

int	*transform_array(char **av, int ac, int *len_total)
{
	int	**array;
	int	*len;
	int	size;
	int	i;
	int	*res;

	*len_total = 0;
	len = NULL;
	array = strings_to_arrays(av, ac, &len, len_total);
	if (!array)
		return (NULL);
	res = malloc(sizeof(int) * *len_total);
	if (!res)
		return (free(array), free(len), NULL);
	i = 0;
	size = 0;
	while (i < ac)
	{
		ft_memcpy(res + size, array[i], len[i] * sizeof(int));
		size += len[i];
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	return (free(array), free(len), res);
}

int	**strings_to_arrays(char **av, int ac, int **len, int *len_total)
{
	int	**array;
	int	i;
	int	j;

	array = malloc(sizeof(int *) * ac);
	if (!array)
		return (NULL);
	*len = malloc(sizeof(int) * ac);
	if (!(*len))
		return (free(array), NULL);
	i = -1;
	while (++i < ac)
	{
		array[i] = ft_strtoi(av[i], &((*len)[i]));
		if (!array[i])
		{
			j = -1;
			while (++j < i)
				free(array[j]);
			return (free(array), free(*len), NULL);
		}
		*len_total += (*len)[i];
	}
	return (array);
}

int	verification(int *array, int size)
{
	int	i;
	int	j;

	if (is_sorted(array, size))
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
