/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:13:31 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 04:11:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stacks.stack_a = ft_init_stack(argc, argv);
	stacks.stack_b = NULL;
	stacks.operations = NULL;
	if (!ft_is_stack_ordered(stacks.stack_a))
		ft_begin_sorting(&stacks);
	ft_print_operations(&stacks);
	ft_stack_clear(&stacks.stack_a);
	ft_stack_clear(&stacks.operations);
	return (0);
}
