/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:02:51 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:10:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
	write(1, "rr\n", 3);
}
