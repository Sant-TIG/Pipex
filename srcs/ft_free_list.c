/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:59:28 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:10:41 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_free_list(t_stack **stack, int len)
{
	t_stack	*tmp;

	tmp = *stack;
	while (len--)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
}
