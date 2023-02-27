/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:43:43 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/27 19:03:20 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strtoi(const char *str, int *size)
{
	char			**to_atoi;
	int				*res;
	unsigned int	len;
	unsigned int	i;

	to_atoi = ft_split(str, ' ');
	if (!to_atoi)
		return (NULL);
	len = 0;
	i = 0;
	while (to_atoi[len])
		len++;
	res = malloc(sizeof(int) * len);
	while (res && i < len)
	{
		res[i] = ft_atoi(to_atoi[i]);
		i++;
	}
	*size = len;
	return (ft_free_split(to_atoi), res);
}