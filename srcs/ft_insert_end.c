/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:00:06 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:02 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_insert_end(int nbr, t_stack **stack)
{
	t_stack	*new;
	t_stack	*last;

	if (!*stack)
	{
		ft_insert_empty(nbr, stack);
		return ;
	}
	last = (*stack)->prev;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
	last->next = new;
}
