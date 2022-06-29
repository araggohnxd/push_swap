/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:32:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/28 23:45:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest(t_stack *stack)
{
	int	biggest;

	biggest = stack->value;
	while (stack->next)
	{
		if (biggest < stack->next->value)
			biggest = stack->next->value;
		stack = stack->next;
	}
	return (biggest);
}

int	ft_get_smallest(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack->next)
	{
		if (smallest > stack->next->value)
			smallest = stack->next->value;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*ft_get_index(t_stack *stack, size_t index)
{
	while (index && stack)
	{
		stack = stack->next;
		--index;
	}
	if (index == 0 && stack)
		return (stack);
	return (NULL);
}

t_stack	*ft_get_value_index(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_put_at_top(t_stack_pair *stacks, t_stack **stack, char stack_id)
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
	if (stack_size - index >= index && stack_id == 'A')
		while ((*stack)->value != top)
			ft_rotate(stacks, RA);
	else if (stack_size - index < index && stack_id == 'A')
		while ((*stack)->value != top)
			ft_reverse_rotate(stacks, RRA);
	else if (stack_size - index >= index && stack_id == 'B')
		while ((*stack)->value != top)
			ft_rotate(stacks, RB);
	else if (stack_size - index < index && stack_id == 'B')
		while ((*stack)->value != top)
			ft_reverse_rotate(stacks, RRB);
}
