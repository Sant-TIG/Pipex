/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:29:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:11 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_insert_nbr(int nbr, int pos, t_stack **stack, int stack_len)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!*stack)
		ft_insert_empty(nbr, stack);
	else if (pos == 1)
		ft_insert_begin(nbr, stack);
	else if (pos == stack_len)
		ft_insert_end(nbr, stack);
	else
	{
		tmp = *stack;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return ;
		while (--pos)
			tmp = tmp->next;
		new->nbr = nbr;
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}
