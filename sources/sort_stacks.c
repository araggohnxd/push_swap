/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:57:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 01:51:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_get_place(t_stack *stack, size_t stack_size, int n)
{
	size_t	i;

	i = 0;
	if (stack->value > n && ft_stack_last(stack)->value < n)
		return (0);
	while (!(stack->value < n && stack->next->value > n)
		&& i < (stack_size - 2))
	{
		stack = stack->next;
		i++;
	}
	return (i + 1);
}

static size_t	ft_getmoves(t_stack *from, t_stack *to)
{
	size_t	index;
	size_t	size;

	size = ft_stack_size(from);
	index = size - ft_stack_size(to) + 1;
	if (index <= size / 2)
		return (index - 1);
	else
		return (size - index);
}

static void	ft_put_at_top(t_stack_pair *stacks, t_stack **stack, char stack_id)
{
	t_stack	*aux;
	size_t	index;
	size_t	stack_size;
	int		top;

	aux = *stack;
	top = (*stack)->top;
	while (aux->value != top)
		aux = aux->next;
	stack_size = ft_stack_size(*stack);
	index = stack_size - ft_stack_size(aux);
	if (stack_size - index < index && stack_id == 'A')
		while ((*stack)->value != top)
			ft_reverse_rotate(stacks, RRA);
	else if (stack_size - index >= index && stack_id == 'A')
		while ((*stack)->value != top)
			ft_rotate(stacks, RA);
	else if (stack_size - index < index && stack_id == 'B')
		while ((*stack)->value != top)
			ft_reverse_rotate(stacks, RRB);
	else if (stack_size - index >= index && stack_id == 'B')
		while ((*stack)->value != top)
			ft_rotate(stacks, RB);
}

static void	ft_analyze_combinations(
	t_stack_pair *stacks, t_stack **stack_a, t_stack **stack_b, size_t b_size)
{
	t_stack	*b_aux;
	t_stack	*a_aux;
	size_t	b_index;
	size_t	a_index;
	size_t	moves;

	b_index = 0;
	moves = ft_stack_size(*stack_a);
	b_aux = *stack_b;
	while (b_index++ < b_size)
	{
		a_index = ft_get_place(*stack_a, ft_stack_size(*stack_a), b_aux->value);
		a_aux = ft_get_index(*stack_a, a_index);
		if (ft_getmoves(*stack_a, a_aux) + ft_getmoves(*stack_b, b_aux) < moves)
		{
			(*stack_a)->top = a_aux->value;
			(*stack_b)->top = b_aux->value;
			moves = ft_getmoves(*stack_a, a_aux) + ft_getmoves(*stack_b, b_aux);
		}
		b_aux = b_aux->next;
	}
	ft_put_at_top(stacks, stack_a, 'A');
	ft_put_at_top(stacks, stack_b, 'B');
}

void	ft_begin_sorting(t_stack_pair *stacks)
{
	ft_split_stack(stacks);
	while (stacks->stack_b)
	{
		ft_analyze_combinations(stacks,
			&stacks->stack_a,
			&stacks->stack_b,
			ft_stack_size(stacks->stack_b));
		ft_push(stacks, PA);
	}
	stacks->stack_a->top = ft_get_smallest(stacks->stack_a);
	ft_put_at_top(stacks, &stacks->stack_a, 'A');
}
