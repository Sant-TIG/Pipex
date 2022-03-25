/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:17:07 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:08:49 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_control_sort(t_stacks *stacks)
{
	if (stacks->utils->stacka_len == 2)
		ft_rotate_a(&stacks->stack_a);
	else if (stacks->utils->stacka_len == 3)
		ft_treat_three_case(&stacks->stack_a);
	else
		ft_sort_a(stacks, stacks->utils->stacka_len);
}
