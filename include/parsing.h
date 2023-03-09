/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loic Cozdenmat <Loic Cozdenmat@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:25:03 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/09 11:25:32 by Loic Cozden      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"

int		*bsort(int *array, int size);
int		*pre_sort(int *array, int size);
int		*transform_array(char **av, int ac, int *len_total);
int		**strings_to_arrays(char **av, int ac, int **len, int *len_total);

/* Verify if the parameters are valid:
** - No duplicate
** - No overflow
** - Non sorted
** - No invalid characters
*/
int		verification(int *array, int size);

/* Tell you if the array of length size is sorted or not */
t_bool	is_sorted(int *array, int size);

#endif