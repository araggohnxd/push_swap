/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:25:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 01:50:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_remaining(t_stack_pair *stacks)
{
	int		a_biggest;
	int		a_smallest;

	a_biggest = ft_get_biggest(stacks->stack_a);
	a_smallest = ft_get_smallest(stacks->stack_a);
	while (!ft_is_stack_ordered(stacks->stack_a)
		|| ft_stack_size(stacks->stack_a) > 2)
	{
		if (stacks->stack_a->value != a_biggest
			&& stacks->stack_a->value != a_smallest)
			ft_push(stacks, PB);
		else
			ft_rotate(stacks, RA);
	}
}

static void	ft_last_retrieve(t_stack_pair *stacks)
{
	size_t	stack_size;
	int		b_biggest;
	int		pivot;

	stack_size = ft_stack_size(stacks->stack_b);
	b_biggest = ft_get_biggest(stacks->stack_b);
	pivot = (b_biggest / 2) + (b_biggest / 6);
	while (--stack_size + 1)
	{
		if (ft_get_biggest(stacks->stack_b) < pivot + 1)
		{
			while (ft_stack_last(stacks->stack_b)->value > (b_biggest / 2) - 1)
				ft_reverse_rotate(stacks, RRB);
			break ;
		}
		if (stacks->stack_b->value > pivot)
			ft_push(stacks, PA);
		else
			ft_rotate(stacks, RB);
	}
}

static void	ft_first_retrieve(t_stack_pair *stacks)
{
	size_t	stack_size;
	int		b_biggest;
	int		pivot;

	stack_size = ft_stack_size(stacks->stack_b);
	b_biggest = ft_get_biggest(stacks->stack_b);
	pivot = b_biggest / 2;
	while (--stack_size + 1)
	{
		if (ft_get_smallest(stacks->stack_b) > pivot + 1)
			break ;
		if (stacks->stack_b->value > pivot + 1)
			ft_push(stacks, PA);
		else
			ft_rotate(stacks, RB);
	}
}

static void	ft_first_split(t_stack_pair *stacks)
{
	size_t	stack_size;
	int		a_biggest;
	int		a_smallest;
	int		pivot;

	stack_size = ft_stack_size(stacks->stack_a);
	a_biggest = ft_get_biggest(stacks->stack_a);
	a_smallest = ft_get_smallest(stacks->stack_a);
	pivot = a_biggest / 2;
	while (--stack_size + 1)
	{
		if (ft_get_smallest(stacks->stack_a) > pivot + 1)
			break ;
		if (stacks->stack_a->value < pivot
			&& (stacks->stack_a)->value != a_smallest)
			ft_push(stacks, PB);
		else
			ft_rotate(stacks, RA);
	}
}

void	ft_split_stack(t_stack_pair *stacks)
{
	ft_first_split(stacks);
	ft_first_retrieve(stacks);
	ft_push_remaining(stacks);
	ft_last_retrieve(stacks);
	ft_push_remaining(stacks);
}
