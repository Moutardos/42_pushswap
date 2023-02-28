/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:20:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/28 12:54:06 by lcozdenm         ###   ########.fr       */
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
	t_stack	*st_a;
	int		s_a;
	t_stack	*st_b;
	int		s_b;
	t_stack	*st_op;
	int		size_op;
}	t_env;

/** OPERATIONS */
int			do_operation(t_env *env, t_operation op);
char		*op_to_str(t_operation op);
void		swap_stack(t_stack **stack);
void		push_stack(t_stack **st_a, t_stack **st_b);
void		rotate_stack(t_stack **stack, int size);
void		reverse_stack(t_stack **stack, int size);
int			get_bmax(int *array, int size);
/** PUSH SWAP **/
t_env		*init_env(int *array, int size);
void		free_env(t_env *env);
t_env		*sort_one(t_env *env, int offset);
#endif