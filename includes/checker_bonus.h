/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:39:47 by maolivei          #+#    #+#             */
/*   Updated: 2022/06/27 00:05:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define OK "\e[0;32mOK\e[0m"
# define KO "\e[0;31mKO\e[0m"
# include "push_swap.h"

void	ft_get_operations(t_stack_pair *stacks);
void	ft_execute_operations(t_stack_pair *stacks);

#endif /* CHECKER_BONUS_H */
