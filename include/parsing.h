/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:25:03 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 20:38:47 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"

int		*bsort(int *array, int size);
int		*pre_sort(int *array, int size);
int		*transform_array(char **av, int ac, int *len_total);
int		**strings_to_arrays(char **av, int ac, int **len, int *len_total);
int		verification(int *array, int size);
#endif