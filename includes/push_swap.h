/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:55:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/20 20:14:16 by maolivei         ###   ########.fr       */
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

typedef struct s_stack_pair {
	t_list	**stack_a;
	t_list	**stack_b;
}	t_stack_pair;

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
int			*ft_numdup(char *number);
int			ft_isnumber(const char *str);
long long	ft_atoll(const char *nptr);
int			ft_is_in_stack(long long number, t_list *stack);

#endif /* PUSH_SWAP_H */
