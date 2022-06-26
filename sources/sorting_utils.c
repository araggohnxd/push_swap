/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:32:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 01:48:23 by maolivei         ###   ########.fr       */
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
