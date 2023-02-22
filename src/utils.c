/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:53:38 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/18 18:06:27 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int *bsort(int *array, int size)
{
	int i;
	int j;
	int tmp;

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