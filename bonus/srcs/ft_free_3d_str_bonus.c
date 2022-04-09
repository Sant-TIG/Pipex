/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d_str_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:52 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:35:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_free_3d_str(char ***str)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			free(str[i][j]);
		free(str[i][j]);
		free(str[i]);
	}
	free(str);
}
