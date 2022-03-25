/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:03:29 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:45 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_sorted_b(t_stack *stack_b)
{
	t_stack	*last;

	last = stack_b->prev;
	if (stack_b != stack_b->next)
	{
		while (stack_b->nbr > stack_b->next->nbr && stack_b != last)
			stack_b = stack_b->next;
		return (stack_b != last);
	}
	return (0);
}
