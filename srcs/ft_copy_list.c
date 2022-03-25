/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:59:55 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:10:35 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_copy_list(t_stack **tmp, t_stack *stack, int len)
{
	int	nbr;
	int	pos;

	pos = 1;
	nbr = stack->nbr;
	while (len--)
	{
		ft_insert_nbr(stack->nbr, pos++, tmp, len);
		stack = stack->next;
	}
}
