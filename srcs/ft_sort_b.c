/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:16:33 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:09:16 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_3s_b(t_stack **stack_a, \
		t_stack **stack_b, t_pushswap **utils, int len)
{
	while (len--)
	{
		if ((*stack_b)->nbr < (*stack_b)->next->nbr)
			ft_swap_b(stack_b);
		else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}	
}

static void	ft_3_b(t_stack **st_a, \
		t_stack **st_b, t_pushswap **utils)
{
	t_stack	*last;

	last = (*st_b)->prev;
	if ((*st_b)->nbr < (*st_b)->next->nbr && (*st_b)->nbr < last->nbr
		&& (*st_b)->next->nbr > last->nbr)
		ft_rotate_b(st_b);
	else if ((*st_b)->nbr > (*st_b)->next->nbr && (*st_b)->nbr < last->nbr)
		ft_reverse_rotate_b(st_b);
	else if ((*st_b)->nbr < (*st_b)->next->nbr && (*st_b)->nbr > last->nbr)
		ft_swap_b(st_b);
	else if ((*st_b)->nbr < (*st_b)->next->nbr && (*st_b)->nbr < last->nbr)
	{
		ft_rotate_b(st_b);
		ft_swap_b(st_b);
	}
	else if ((*st_b)->nbr > (*st_b)->next->nbr && (*st_b)->nbr > last->nbr)
	{
		ft_reverse_rotate_b(st_b);
		ft_swap_b(st_b);
	}	
	ft_push_a(st_a, st_b, utils);
	ft_push_a(st_a, st_b, utils);
	ft_push_a(st_a, st_b, utils);
}

static void	ft_general_cases_b(t_stacks *stacks, t_stack *copy, int len, int *i)
{
	t_stack	*tmp;
	int		max_push;
	int		pivot;

	pivot = ft_quick_sort(&copy, 1, len, stacks);
	tmp = stacks->stack_b;
	max_push = len / 2 + len % 2;
	while (max_push)
	{
		if (tmp->nbr >= pivot)
		{
			tmp = tmp->next;
			ft_push_a(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
			max_push--;
		}
		else
		{
			tmp = tmp->next;
			ft_rotate_b(&stacks->stack_b);
			(*i)++;
		}
	}
}

static int	ft_specific_cases_b(t_stacks *stacks, t_stack *copy, int len)
{	
	if (!ft_check_sorted_b(copy))
	{
		while (len--)
		{
			ft_push_a(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
			copy = copy->next;
		}
		return (1);
	}
	else if (len <= 3)
	{
		if (len == 2)
		{
			ft_swap_b(&stacks->stack_b);
			ft_push_a(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
			ft_push_a(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
		}
		else if (len == 3 && stacks->utils->stackb_len == 3)
			ft_3_b(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
		else if (len == 3)
			ft_3s_b(&stacks->stack_a, &stacks->stack_b, &stacks->utils, len);
		return (1);
	}
	return (0);
}

void	ft_sort_b(t_stacks *stacks, int len)
{
	t_stack	*copy;
	int		len1;
	int		i;

	copy = NULL;
	len1 = len / 2;
	i = 0;
	ft_copy_list(&copy, stacks->stack_b, len);
	if (ft_specific_cases_b(stacks, copy, len))
	{
		ft_free_list(&copy, len);
		return ;
	}
	ft_general_cases_b(stacks, copy, len, &i);
	ft_free_list(&copy, len);
	len = len / 2 + len % 2;
	if (len1 != stacks->utils->stackb_len)
	{
		while (i--)
			ft_reverse_rotate_b(&stacks->stack_b);
	}
	ft_sort_a(stacks, len);
	ft_sort_b(stacks, len1);
}
