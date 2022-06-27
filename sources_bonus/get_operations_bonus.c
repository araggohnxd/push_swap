/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:58:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/27 10:50:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_parse_operation(char *operation, t_stack_pair *stacks)
{
	char	**ops;
	size_t	index;

	ops = ft_split(OPERATIONS, ' ');
	if (!ops)
		ft_error_and_exit(stacks);
	index = 1;
	while (ops[index])
	{
		if (ft_memcmp(operation, ops[index], ft_strlen(ops[index])) == 0)
		{
			ft_stack_add_end(&stacks->operations, ft_stack_new(index));
			break ;
		}
		++index;
	}
	if (!ops[index])
		ft_error_and_exit(stacks);
	ft_free_matrix((void *) &ops);
}

void	ft_get_operations(t_stack_pair *stacks)
{
	char	*op;

	op = NULL;
	while (TRUE)
	{
		op = ft_gnl(STDIN);
		if (!op)
			break ;
		ft_parse_operation(op, stacks);
		ft_memfree((void *) &op);
	}
}
