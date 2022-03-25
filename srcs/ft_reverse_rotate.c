/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:48 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:10:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
	write(1, "rrr\n", 4);
}
