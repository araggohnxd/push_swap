/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:55:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 23:40:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_stack_add_end(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
		ft_stack_last(*stack)->next = new;
}

void	ft_stack_add_start(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (*stack)
		new->next = *stack;
	*stack = new;
}

t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}
