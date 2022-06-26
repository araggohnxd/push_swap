/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:22:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 20:27:34 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_at_top_tiny(t_stack_pair *stacks)
{
	t_stack	*aux;
	size_t	index;
	size_t	stack_size;
	int		top;

	aux = stacks->stack_a;
	top = aux->top;
	while (aux->value != top)
		aux = aux->next;
	stack_size = ft_stack_size(stacks->stack_a);
	index = stack_size - ft_stack_size(aux);
	if (stack_size - index >= index)
		while (stacks->stack_a->value != top)
			ft_rotate(stacks, RA);
	else if (stack_size - index < index)
		while (stacks->stack_a->value != top)
			ft_reverse_rotate(stacks, RRA);
}

static void	ft_sort_tiny_a(t_stack_pair *stacks)
{
	t_stack	*aux;
	int		smallest;
	int		biggest;
	size_t	i_small;
	size_t	i_big;

	aux = stacks->stack_a;
	smallest = ft_get_smallest(aux);
	biggest = ft_get_biggest(aux);
	i_small = 3 - ft_stack_size(ft_get_value_index(aux, smallest)) + 1;
	i_big = 3 - ft_stack_size(ft_get_value_index(aux, biggest)) + 1;
	if (i_small == 2 && i_big == 3)
		ft_swap(stacks, SA);
	else if (i_small == 3 && i_big == 1)
		ft_swap(stacks, SA);
	else if (i_small == 2 && i_big == 1)
		ft_rotate(stacks, RA);
	else if (i_small == 1 && i_big == 2)
		ft_swap(stacks, SA);
	else if (i_small == 3 && i_big == 2)
		ft_reverse_rotate(stacks, RRA);
}

void	ft_sort_tiny_stack(t_stack_pair *stacks)
{
	int	a_smallest;

	while (ft_stack_size(stacks->stack_a) > 3)
	{
		a_smallest = ft_get_smallest(stacks->stack_a);
		stacks->stack_a->top = a_smallest;
		ft_put_at_top_tiny(stacks);
		ft_push(stacks, PB);
	}
	while (!ft_is_stack_ordered(stacks->stack_a))
		ft_sort_tiny_a(stacks);
	while (stacks->stack_b)
		ft_push(stacks, PA);
}
