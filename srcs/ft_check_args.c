/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:58:32 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:11:29 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_digit_str(args[i]))
		i++;
	return (!args[i]);
}
