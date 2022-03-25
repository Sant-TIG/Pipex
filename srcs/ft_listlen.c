/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:39:43 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:18 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_listlen(t_stack *stack_a)
{
	int		len;
	t_stack	*last;

	if (!stack_a)
		return (0);
	last = stack_a->prev;
	len = 1;
	stack_a = stack_a->next;
	while (stack_a->prev != last)
	{
		len++;
		stack_a = stack_a->next;
	}
	return (len);
}
