/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:57:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/22 19:43:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		ft_printf("empty stack\n");
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

t_stack	*ft_get_smallest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	while (stack->next)
	{
		if (smallest->value > stack->next->value)
			smallest = stack->next;
		stack = stack->next;
	}
	return (smallest);
}

int	ft_get_index_value(t_stack *stack, size_t index)
{
	while (--index && stack)
		stack = stack->next;
	if (index == 0 && stack)
		return (stack->value);
	return (FALSE);
}

void	ft_sort_before_middle(
	t_stack_pair *stacks, size_t index, t_stack *smallest)
{
	while (--index)
	{
		if ((index + 1) == 2
			&& ft_get_index_value(*(stacks->stack_a), 1) == smallest->value + 1)
			ft_swap(stacks, SA);
		else
			ft_rotate(stacks, RA);
	}
}

void	ft_sort_after_middle(
	t_stack_pair *stacks, size_t index, size_t size, t_stack *smallest)
{
	while (++index <= size + 1)
	{
		if ((index - 1) == 2
			&& ft_get_index_value(*(stacks->stack_a), 1) == smallest->value + 1)
			ft_swap(stacks, SA);
		else
			ft_reverse_rotate(stacks, RRA);
	}
}

void	ft_sort_stacks(t_stack_pair *stacks)
{
	t_stack	*smallest;
	size_t	stack_size;
	size_t	index_smallest;

	// print_stack(*(stacks->stack_a));
	while (*(stacks->stack_a) && !ft_is_stack_ordered(*(stacks->stack_a)))
	{
		stack_size = ft_stack_size(*(stacks->stack_a));
		smallest = ft_get_smallest(*(stacks->stack_a));
		index_smallest = stack_size - ft_stack_size(smallest) + 1;
		if (index_smallest > (stack_size / 2) + 1)
			ft_sort_after_middle(stacks, index_smallest, stack_size, smallest);
		else
			ft_sort_before_middle(stacks, index_smallest, smallest);
		if (!ft_is_stack_ordered(*(stacks->stack_a)))
			ft_push(stacks, PB);
		// print_stack(*(stacks->stack_a));
		// print_stack(*(stacks->stack_b));
	}
	while (*(stacks->stack_b))
		ft_push(stacks, PA);
	// ft_printf("\n\n\n\n\n");
	// print_stack(*(stacks->stack_a));
	// print_stack(*(stacks->stack_b));
}
