/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:05:13 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:09:45 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_get_utils(t_stack *tmp, t_stacks *stacks, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = end;
	stacks->nbrtmp = tmp;
	stacks->pivot_index = tmp;
	stacks->pivot_nbr = tmp;
	while (--i)
	{
		stacks->pivot_index = stacks->pivot_index->next;
		stacks->nbrtmp = stacks->nbrtmp->next;
	}
	while (--j)
		stacks->pivot_nbr = stacks->pivot_nbr->next;
}

static void	ft_do_partition(t_stacks *stacks, int start, int end)
{
	int		tmp;
	int		j;

	j = end - start + 1;
	while (--j)
	{
		if (stacks->nbrtmp->nbr <= stacks->pivot_nbr->nbr)
		{
			tmp = stacks->nbrtmp->nbr;
			stacks->nbrtmp->nbr = stacks->pivot_index->nbr;
			stacks->pivot_index->nbr = tmp;
			stacks->pivot_index = stacks->pivot_index->next;
		}
		stacks->nbrtmp = stacks->nbrtmp->next;
	}
	tmp = stacks->pivot_index->nbr;
	stacks->pivot_index->nbr = stacks->pivot_nbr->nbr;
	stacks->pivot_nbr->nbr = tmp;
}

static int	ft_partition(t_stack **tmp, int start, int end, t_stacks *stacks)
{
	int	i;

	i = start;
	ft_get_utils(*tmp, stacks, start, end);
	ft_do_partition(stacks, start, end);
	i = 1;
	stacks->nbrtmp = *tmp;
	while (stacks->nbrtmp->nbr != stacks->pivot_index->nbr)
	{
		stacks->nbrtmp = stacks->nbrtmp->next;
		i++;
	}
	return (i);
}

int	ft_quick_sort(t_stack **stack_a, int start, int end, t_stacks *stacks)
{
	int		pivot_index;
	t_stack	*tmp;

	tmp = *stack_a;
	if (start < end && ft_check_sorted(tmp))
	{
		pivot_index = ft_partition(&tmp, start, end, stacks);
		ft_quick_sort(&tmp, start, pivot_index - 1, stacks);
		ft_quick_sort(&tmp, pivot_index + 1, end, stacks);
	}
	if (end % 2 != 0)
		pivot_index = (end / 2) + 1;
	pivot_index = end / 2;
	while (pivot_index--)
		tmp = tmp->next;
	return (tmp->nbr);
}
