/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:55:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/23 17:28:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STDERR 2
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "../libft/libft.h"

enum e_operation_id {
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
	RRR
};

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_pair {
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stack_pair;

/*
	SORTING
*/
void		ft_sort_stacks(t_stack_pair *stacks);

/*
	OPERATIONS
*/
void		ft_swap(t_stack_pair *stacks, int operation_id);
void		ft_push(t_stack_pair *stacks, int operation_id);
void		ft_rotate(t_stack_pair *stacks, int operation_id);
void		ft_reverse_rotate(t_stack_pair *stacks, int operation_id);

/*
	UTILS
*/
long long	ft_atoll(const char *nptr);
int			ft_is_number_str(const char *str);
int			ft_is_in_stack(long long number, t_stack *stack);
int			ft_is_stack_ordered(t_stack *stack);

/*
	LINKED LIST
*/
t_stack		*ft_stack_new(int value);
t_stack		*ft_stack_last(t_stack *stack);
size_t		ft_stack_size(t_stack *stack);
void		ft_stack_clear(t_stack **stack);
void		ft_stack_add_end(t_stack **stack, t_stack *new);
void		ft_stack_add_start(t_stack **stack, t_stack *new);

#endif /* PUSH_SWAP_H */
