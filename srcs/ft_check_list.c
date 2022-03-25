/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:58:42 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_list(t_stack *stack_a, t_pushswap *utils)
{
	t_stack	*last;
	t_stack	*tmp1;
	int		len;
	int		len1;

	len = utils->stacka_len;
	last = stack_a->prev;
	tmp1 = stack_a;
	while (--len)
	{
		len1 = len;
		tmp1 = tmp1->next;
		while (len1--)
		{
			if (stack_a->nbr == tmp1->nbr)
				return (0);
			tmp1 = tmp1->next;
		}
		stack_a = stack_a->next;
		tmp1 = stack_a;
	}
	return (1);
}
