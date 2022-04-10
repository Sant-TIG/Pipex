/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:06:33 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:06:40 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  TYPE
  ****
  General function.

  PARAMETERS
  **********
  str --> the two-dimensional array to free

  DESCRIPTION
  ***********
  The ft_free_3d_str() frees the dynamic memory space where the three_dimensional
  array passed as a parameter is stored.

  Since this array is made up of two-dimensional arrays, it uses the
  ft_free_2d_str() function to free each them.
*/

/*  ALTERNATIVE FUNCTION  */
/*void	ft_free_3d_str(char ***str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		ft_free_2d_str(str[i]);
	free(str);
}*/

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
