/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:34:31 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/20 21:02:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_pair *stacks, int operation_id)
{
	t_stack	*dst;
	t_stack	*src;
	int		aux;

	dst = NULL;
	if (operation_id == SS || operation_id == RR)
	{
		ft_swap(stacks, SA);
		ft_swap(stacks, SB);
	}
	else if (operation_id == SA || operation_id == RA)
		dst = *(stacks->stack_a);
	else if (operation_id == SB || operation_id == RB)
		dst = *(stacks->stack_b);
	if (!dst)
		return ;
	src = dst->next;
	aux = dst->value;
	dst->value = src->value;
	src->value = aux;
}

void	ft_push(t_stack_pair *stacks, int operation_id)
{
	t_stack	**dst;
	t_stack	**src;
	t_stack	*pushed_node;

	if (operation_id == PA)
	{
		dst = stacks->stack_b;
		src = stacks->stack_a;
	}
	else if (operation_id == PB)
	{
		dst = stacks->stack_a;
		src = stacks->stack_b;
	}
	if (!dst || !*dst)
		return ;
	pushed_node = *dst;
	*dst = (*dst)->next;
	pushed_node->next = NULL;
	ft_stack_add_start(src, pushed_node);
}

void	ft_rotate(t_stack_pair *stacks, int operation_id)
{
	t_stack	**stack;
	t_stack	*old_head;

	stack = NULL;
	if (operation_id == RR)
	{
		ft_rotate(stacks, RA);
		ft_rotate(stacks, RB);
	}
	else if (operation_id == RA)
		stack = stacks->stack_a;
	else if (operation_id == RB)
		stack = stacks->stack_b;
	if (!stack || !*stack)
		return ;
	old_head = *stack;
	*stack = (*stack)->next;
	old_head->next = NULL;
	ft_stack_add_end(stack, old_head);
}

void	ft_reverse_rotate(t_stack_pair *stacks, int operation_id)
{
	t_stack	**stack;
	t_stack	*old_tail;
	size_t	stack_size;

	stack = NULL;
	if (operation_id == RRR)
	{
		ft_reverse_rotate(stacks, RRA);
		ft_reverse_rotate(stacks, RRB);
	}
	else if (operation_id == RRA)
		stack = stacks->stack_a;
	else if (operation_id == RRB)
		stack = stacks->stack_b;
	if (!stack || !*stack)
		return ;
	stack_size = ft_stack_size(*stack);
	old_tail = ft_stack_last(*stack);
	ft_stack_add_start(stack, old_tail);
	while (--stack_size)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = old_tail;
}
