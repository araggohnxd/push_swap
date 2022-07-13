/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 04:10:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/07/13 14:20:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_operations(t_stack_pair *stacks)
{
	t_stack	*aux;
	char	**operations;

	aux = stacks->operations;
	operations = ft_split(OPERATIONS, ' ');
	if (!operations)
		ft_error_and_exit(stacks);
	while (aux)
	{
		if (aux->value != 0)
			ft_printf("%s", operations[aux->value]);
		aux = aux->next;
	}
	ft_free_matrix((void *) &operations);
}

void	ft_store_operation(t_stack_pair *stacks, int operation_id)
{
	t_stack	*last;

	if (!stacks->operations)
		stacks->operations = ft_stack_new(operation_id);
	else
	{
		last = ft_stack_last(stacks->operations);
		if ((operation_id == RA && last->value == RB)
			|| (operation_id == RB && last->value == RA))
			last->value = RR;
		else if ((operation_id == RRA && last->value == RRB)
			|| (operation_id == RRB && last->value == RRA))
			last->value = RRR;
		else if ((operation_id == PB && last->value == PA)
			|| (operation_id == PA && last->value == PB))
			last->value = 0;
		else
			ft_stack_add_end(&stacks->operations, ft_stack_new(operation_id));
	}
}
