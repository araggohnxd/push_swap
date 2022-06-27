/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:59:51 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/27 00:05:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.operations = NULL;
	ft_init_stack(&stacks, argc, argv);
	ft_get_operations(&stacks);
	ft_execute_operations(&stacks);
	if (ft_is_stack_ordered(stacks.stack_a) && !stacks.stack_b)
		ft_putendl_fd(OK, STDOUT_FILENO);
	else
		ft_putendl_fd(KO, STDOUT_FILENO);
	ft_stack_clear(&stacks.stack_a);
	ft_stack_clear(&stacks.stack_b);
	ft_stack_clear(&stacks.operations);
	return (0);
}
