/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:53:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/23 17:33:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(t_stack *stack)
{
	ft_putendl_fd("Error", STDERR);
	if (stack)
		ft_stack_clear(&stack);
	exit(EXIT_FAILURE);
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack		*aux;
	size_t		index;
	long long	nbr;

	aux = NULL;
	index = 0;
	while (++index < (size_t)argc)
	{
		if (!ft_is_number_str(argv[index]))
			ft_error_and_exit(aux);
		nbr = ft_atoll(argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_is_in_stack(nbr, aux))
			ft_error_and_exit(aux);
		if (index == 1)
			aux = ft_stack_new((int) nbr);
		else
			ft_stack_add_end(&aux, ft_stack_new((int) nbr));
	}
	return (aux);
}

void	ft_clear_stacks(t_stack_pair *stacks)
{
	ft_stack_clear(&stacks->stack_a);
	ft_stack_clear(&stacks->stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;

	if (argc <= 2)
		exit(EXIT_SUCCESS);

	stacks.stack_a = ft_init_stack(argc, argv);
	stacks.stack_b = NULL;
	ft_sort_stacks(&stacks);
	ft_clear_stacks(&stacks);
	return (0);
}
