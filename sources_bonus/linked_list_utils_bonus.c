/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:37:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 23:40:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

size_t	ft_stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*aux_node;

	aux_node = *stack;
	while (aux_node)
	{
		aux_node = aux_node->next;
		free(*stack);
		*stack = aux_node;
	}
	*stack = NULL;
}
