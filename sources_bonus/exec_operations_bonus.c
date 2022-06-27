/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:00:51 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/27 00:00:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_execute_operations(t_stack_pair *stacks)
{
	t_stack	*aux;

	aux = stacks->operations;
	while (aux)
	{
		if (aux->value == SA || aux->value == SB || aux->value == SS)
			ft_swap(stacks, aux->value);
		else if (aux->value == PA || aux->value == PB)
			ft_push(stacks, aux->value);
		else if (aux->value == RA || aux->value == RB || aux->value == RR)
			ft_rotate(stacks, aux->value);
		else if (aux->value == RRA || aux->value == RRB || aux->value == RRR)
			ft_reverse_rotate(stacks, aux->value);
		aux = aux->next;
	}
}
