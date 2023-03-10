/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 20:37:42 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/** STACK **/
t_stack	*new_stack(int *data, int size);
t_stack	*add_stack(t_stack **stack, int data);
void	del_stack(t_stack **stack);
void	free_stack(t_stack **stack, int size);
void	print_stack(t_stack *stack, t_bool reverse);

#endif
