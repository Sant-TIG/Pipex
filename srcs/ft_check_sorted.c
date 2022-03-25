/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:58:47 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:39 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_sorted(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a->prev;
	if (stack_a != stack_a->next)
	{
		while (stack_a->nbr < stack_a->next->nbr && stack_a != last)
			stack_a = stack_a->next;
		return (stack_a != last);
	}
	return (0);
}
