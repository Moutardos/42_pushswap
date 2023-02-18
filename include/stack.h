/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 12:51:59 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_stack;

s_stack	*new_stack(int *data, int size);
void	add_stack(t_stack **stack, int data);
void 	del_stack(t_stack **stack);
void 	free_stack(t_stack **stack);
#endif
