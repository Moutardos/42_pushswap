/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:20:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/03/06 20:46:31 by lcozdenm         ###   ########.fr       */
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
/* Do an operation on the stacks 
 * Return -1 if an error occured
 * Return 0 if the operation was successful
 * Return the operation if the operation was not successful
 */
int		do_operation(t_env *env, t_operation op);

/* Return the string representation of an operation */
char	*op_to_str(t_operation op);

/* Swap the first two elements of a stack */
void	swap_stack(t_stack **stack);

/* Push the first element of stack b to stack a */
void	push_stack(t_stack **st_a, t_stack **st_b);

/* Rotate the stack to the top */
void	rotate_stack(t_stack **stack, int size);

/* Rotate the stack to the bottom */
void	reverse_stack(t_stack **stack, int size);

/** PUSH SWAP **/
/* Initialize the environment */
t_env	*init_env(int *array, int size);

/* Free the environment */
void	free_env(t_env *env);

/* Sort the stack using the radix algrithm, offset
   is telling which bit to sort */
t_env	*radix(t_env *env, int offset);

/* Sort the stack using the loic algorithm,
   either a lil_sort if the size is equal to 3,
   or a five_sort if the size is equal to 5,
   or a radix sort if the size is greater than 5 */
t_env	*loic_sort(t_env *env, int bitsize);\

/* Sort the stack if the size is equal to 3 */
t_env	*lil_sort(t_env *env);

/* Sort the stack if the size is equal to 5,
   push the 2 biggest elements to stack b before doing
   a lil_sort on stack a */
t_env	*five_sort(t_env *env);

/** UTILITIES **/
/* Tell you if the array of length size is sorted or not */
t_bool	is_sorted(int *array, int size);

#endif