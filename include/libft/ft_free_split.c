/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:42:50 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/27 18:47:42 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_free_split(char **s)
{
	char	**curr;

	curr = s;
	while (*curr)
	{
		free(*curr);
		curr++;
	}
	free(s);
}
