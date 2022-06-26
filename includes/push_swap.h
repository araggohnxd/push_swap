/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:55:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 04:10:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# define STDERR 2
# define OPERATIONS "sa sb ss pa pb ra rb rr rra rrb rrr"
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

typedef long long	t_llong;

typedef struct s_stack {
	int				value;
	int				top;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_pair {
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*operations;
}	t_stack_pair;

/*
	SORTING
*/
t_stack	*ft_init_stack(int argc, char **argv);
void	ft_begin_sorting(t_stack_pair *stacks);
void	ft_split_stack(t_stack_pair *stacks);

/*
	SORTING UTILS
*/
int		ft_get_smallest(t_stack *stack);
int		ft_get_biggest(t_stack *stack);
t_stack	*ft_get_index(t_stack *stack, size_t index);

/*
	OPERATIONS
*/
void	ft_swap(t_stack_pair *stacks, int operation_id);
void	ft_push(t_stack_pair *stacks, int operation_id);
void	ft_rotate(t_stack_pair *stacks, int operation_id);
void	ft_reverse_rotate(t_stack_pair *stacks, int operation_id);
void	ft_store_operation(t_stack_pair *stacks, int operation_id);
void	ft_print_operations(t_stack_pair *stacks);

/*
	UTILS
*/
t_llong	ft_atoll(const char *nptr);
int		ft_is_number_str(const char *str);
int		ft_is_in_stack(long long number, t_stack *stack);
int		ft_is_stack_ordered(t_stack *stack);

/*
	LINKED LIST
*/
t_stack	*ft_stack_new(int value);
t_stack	*ft_stack_last(t_stack *stack);
size_t	ft_stack_size(t_stack *stack);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_add_end(t_stack **stack, t_stack *new);
void	ft_stack_add_start(t_stack **stack, t_stack *new);

#endif /* PUSH_SWAP_H */
