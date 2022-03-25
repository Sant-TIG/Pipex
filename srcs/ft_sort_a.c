/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:25:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:09:07 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	ft_ut(t_stack **st_a, t_stack **st_b, t_pushswap **utils, int len)
{
	t_stack	*last;

	last = *st_a;
	while (--len)
		last = last->next;
	if (((*st_a)->nbr < (*st_a)->next->nbr) && (*st_a)->nbr < last->nbr)
	{
		ft_push_b(st_a, st_b, utils);
		ft_swap_a(st_a);
		ft_push_a(st_a, st_b, utils);
		return (1);
	}
	else if ((*st_a)->nbr < (*st_a)->next->nbr && (*st_a)->nbr > last->nbr)
	{
		ft_push_b(st_a, st_b, utils);
		ft_swap_a(st_a);
		ft_push_a(st_a, st_b, utils);
		ft_swap_a(st_a);
		return (1);
	}
	return (0);
}

static void	ft_treat_three_special_case_a(t_stack **st_a, \
		t_stack **st_b, t_pushswap **utils, int len)
{
	t_stack	*last;

	last = *st_a;
	if (ft_ut(st_a, st_b, utils, len))
		return ;
	while (--len)
		last = last->next;
	if ((*st_a)->nbr > (*st_a)->next->nbr && (*st_a)->nbr > last->nbr
		&& (*st_a)->next->nbr > last->nbr)
	{
		ft_swap_a(st_a);
		ft_push_b(st_a, st_b, utils);
		ft_swap_a(st_a);
		ft_push_a(st_a, st_b, utils);
		ft_swap_a(st_a);
	}
	else if (((*st_a)->nbr > (*st_a)->next->nbr) && ((*st_a)->nbr < last->nbr))
		ft_swap_a(st_a);
	else if ((*st_a)->nbr > (*st_a)->next->nbr && (*st_a)->nbr > last->nbr)
	{
		ft_swap_a(st_a);
		ft_push_b(st_a, st_b, utils);
		ft_swap_a(st_a);
		ft_push_a(st_a, st_b, utils);
	}
}

static void	ft_general_cases_a(t_stacks *stacks, t_stack *copy, int len, int *i)
{
	t_stack	*tmp;
	int		max_push;
	int		pivot;

	pivot = ft_quick_sort(&copy, 1, len, stacks);
	tmp = stacks->stack_a;
	max_push = len / 2;
	while (max_push)
	{
		if (tmp->nbr < pivot)
		{
			tmp = tmp->next;
			ft_push_b(&stacks->stack_a, &stacks->stack_b, &stacks->utils);
			max_push--;
		}
		else
		{
			tmp = tmp->next;
			ft_rotate_a(&stacks->stack_a);
			(*i)++;
		}
	}
}

static int	ft_specific_cases_a(t_stacks *stacks, t_stack *copy, int len)
{
	if (ft_check_sorted(copy))
	{
		if (len == 2)
		{
			ft_swap_a(&stacks->stack_a);
			return (0);
		}
		else if (len == 3 && stacks->utils->stacka_len == 3)
		{
			ft_treat_three_case(&stacks->stack_a);
			return (0);
		}
		else if (len == 3)
		{
			ft_treat_three_special_case_a(&stacks->stack_a, &stacks->stack_b, \
					&stacks->utils, len);
			return (0);
		}
		return (1);
	}
	return (0);
}

void	ft_sort_a(t_stacks *stacks, int len)
{
	t_stack	*copy;
	int		len1;
	int		i;

	copy = NULL;
	i = 0;
	len1 = len / 2;
	ft_copy_list(&copy, stacks->stack_a, len);
	if (!ft_specific_cases_a(stacks, copy, len))
	{
		ft_free_list(&copy, len);
		return ;
	}
	ft_general_cases_a(stacks, copy, len, &i);
	ft_free_list(&copy, len);
	len = len / 2 + len % 2;
	if (len != stacks->utils->stacka_len && stacks->utils->stacka_len > 3)
	{
		while (i--)
			ft_reverse_rotate_a(&stacks->stack_a);
	}
	ft_sort_a(stacks, len);
	ft_sort_b(stacks, len1);
}
