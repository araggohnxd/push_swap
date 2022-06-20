/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:53:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/20 20:13:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(t_list *stack)
{
	ft_putendl_fd("Error", STDERR);
	if (stack)
		ft_lstclear(&stack, free);
	exit(EXIT_FAILURE);
}

t_list	*ft_init_stack(int argc, char **argv)
{
	t_list		*aux;
	size_t		index;
	long long	nbr;

	aux = NULL;
	index = 0;
	while (++index < (size_t)argc)
	{
		if (!ft_isnumber(argv[index]))
			ft_error_and_exit(aux);
		nbr = ft_atoll(argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_is_in_stack(nbr, aux))
			ft_error_and_exit(aux);
		if (index == 1)
			aux = ft_lstnew(ft_numdup(argv[index]));
		else
			ft_lstadd_back(&aux, ft_lstnew(ft_numdup(argv[index])));
	}
	return (aux);
}

void	ft_clear_stacks(t_stack_pair *stacks)
{
	ft_lstclear(stacks->stack_a, free);
	ft_lstclear(stacks->stack_b, free);
}

int	main(int argc, char **argv)
{
	t_stack_pair	stacks;
	t_list			*stack_a;
	t_list			*stack_b;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	stack_a = ft_init_stack(argc, argv);
	stack_b = NULL;
	stacks.stack_a = &stack_a;
	stacks.stack_b = &stack_b;
	return (0);
}
