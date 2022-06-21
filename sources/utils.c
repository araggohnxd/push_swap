/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:13:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/20 20:55:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *nptr)
{
	int			is_neg;
	long long	result;

	while (ft_isspace(*nptr))
		nptr++;
	is_neg = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_neg = -1;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
		result = (result * 10) + (*nptr++ - '0');
	return (result * is_neg);
}

int	*ft_numdup(char *number)
{
	int		*dup;

	dup = (int *) malloc(sizeof(int));
	if (!dup)
		return (NULL);
	*dup = ft_atoi(number);
	return (dup);
}

int	ft_isnumber(const char *str)
{
	size_t	index;

	index = 0;
	if (str[index] == '-')
		++index;
	while (str[index])
		if (!ft_isdigit(str[index++]))
			return (FALSE);
	return (TRUE);
}

int	ft_is_in_stack(long long number, t_stack *stack)
{
	while (stack)
	{
		if ((int) number == stack->value)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}
