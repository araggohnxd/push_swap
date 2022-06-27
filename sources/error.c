/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:54:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/27 09:55:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(t_stack_pair *stacks)
{
	ft_putendl_fd("Error", STDERR);
	ft_stack_clear(&stacks->stack_a);
	ft_stack_clear(&stacks->stack_b);
	ft_stack_clear(&stacks->operations);
	exit(EXIT_FAILURE);
}
