/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:53:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 23:40:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error_and_exit(t_stack_pair *stacks)
{
	ft_putendl_fd("Error", STDERR);
	ft_stack_clear(&stacks->stack_a);
	ft_stack_clear(&stacks->stack_b);
	ft_stack_clear(&stacks->operations);
	exit(EXIT_FAILURE);
}

void	ft_init_stack(t_stack_pair *stacks, int argc, char **argv)
{
	size_t	index;
	t_llong	nbr;

	index = 0;
	while (++index < (size_t)argc)
	{
		if (!ft_is_number_str(argv[index]))
			ft_error_and_exit(stacks);
		nbr = ft_atoll(argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN
			|| ft_is_in_stack(nbr, stacks->stack_a))
			ft_error_and_exit(stacks);
		ft_stack_add_end(&stacks->stack_a, ft_stack_new((int) nbr));
	}
}
