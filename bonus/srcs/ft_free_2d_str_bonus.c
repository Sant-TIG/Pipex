/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_str_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:43 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:35:44 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_free_2d_str(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}
