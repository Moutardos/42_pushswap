/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:20:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/17 13:07:03 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "stack.h"

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NONE,
	END
}	t_operation;

typedef struct s_env
{
	t_stack	*stack_a;
	int		size_a;
	t_stack *stack_b;
	int		size_b;
	t_stack	*stack_op;
	int		size_op;
}	t_env;

int			do_operation(t_env *env, t_operation op);
t_operation	str_to_operation(char *str);
t_stack		*swap_stack(t_stack **stack);
void 		push_stack(t_stack **stack_a, t_stack **stack_b);
void		rotate_stack(t_stack **stack);

#endif