/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:58:15 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:09:58 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	ft_insert_end2(int nbr, t_stack **stack)
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

static int	ft_treat_args(char **args, t_stacks *stacks)
{
	if (!ft_check_args(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (*args)
		ft_insert_end2(ft_atoi(*args++), &stacks->stack_a);
	stacks->utils->stacka_len = ft_listlen(stacks->stack_a);
	if (!ft_check_list(stacks->stack_a, stacks->utils))
	{
		ft_free_list(&stacks->stack_a, stacks->utils->stacka_len);
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_check_sorted(stacks->stack_a))
	{
		ft_free_list(&stacks->stack_a, stacks->utils->stacka_len);
		return (0);
	}
	return (1);
}

static void	ft_init_struct(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->utils->stacka_len = 0;
	stacks->utils->stackb_len = 0;
}

static void	ft_treat_case_one(char *argv, t_stacks *stacks)
{
	char	**args;

	args = ft_split(argv, ' ');
	if (!ft_treat_args(args, stacks))
	{
		ft_free_args(args);
		return ;
	}
	ft_free_args(args);
	ft_control_sort(stacks);
	ft_free_list(&stacks->stack_a, stacks->utils->stacka_len);
}

int	main(int argc, char **argv)
{	
	t_stacks	stacks;

	stacks.utils = (t_pushswap *)malloc(sizeof(t_pushswap));
	ft_init_struct(&stacks);
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			ft_treat_case_one(*argv, &stacks);
		else
		{
			if (!ft_treat_args(argv, &stacks))
			{
				free(stacks.utils);
				return (0);
			}
			ft_control_sort(&stacks);
			ft_free_list(&stacks.stack_a, stacks.utils->stacka_len);
		}
	}
	//ft_free_list(&stacks.stack_a, stacks.utils->stacka_len);
	free(stacks.utils);
	return (0);
}
