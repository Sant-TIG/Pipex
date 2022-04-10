/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:06:13 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:06:29 by sperez-p         ###   ########.fr       */
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
  The ft_free_2d_str() frees the dynamic memory space where the two_dimensional
  array passed as a parameter is stored.
*/

void	ft_free_2d_str(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}
