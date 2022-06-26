/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:53:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/26 02:39:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error_and_exit(t_stack *stack)
{
	ft_putendl_fd("Error", STDERR);
	if (stack)
		ft_stack_clear(&stack);
	exit(EXIT_FAILURE);
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*aux;
	size_t	index;
	t_llong	nbr;

	aux = NULL;
	index = 0;
	while (++index < (size_t)argc)
	{
		if (!ft_is_number_str(argv[index]))
			ft_error_and_exit(aux);
		nbr = ft_atoll(argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_is_in_stack(nbr, aux))
			ft_error_and_exit(aux);
		ft_stack_add_end(&aux, ft_stack_new((int) nbr));
	}
	return (aux);
}
