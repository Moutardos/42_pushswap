/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:43:43 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/01 10:39:03 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strtoi(const char *str, int *size)
{
	char			**tatoi;
	int				*res;
	unsigned int	len;
	unsigned int	i;

	tatoi = ft_split(str, ' ');
	if (!tatoi)
		return (NULL);
	len = -1;
	while (tatoi[++len])
	{
		i = -1;
		while (tatoi[len][++i])
			if (!ft_isdigit(tatoi[len][i]) || (i == 0 && tatoi[len][i] == '-'))
				return (ft_free_split(tatoi), NULL);
	}
	res = malloc(sizeof(int) * len);
	i = -1;
	while (res && ++i < len)
		res[i] = ft_atoi(tatoi[i]);
	*size = len;
	return (ft_free_split(tatoi), res);
}
