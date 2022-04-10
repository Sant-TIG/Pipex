/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:04:18 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:04:25 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  PARAMETERS
  **********
  env_path --> two-dimensional array containing the paths within environment
               variable PATH.
  cmd      --> the main part of the command

  DESCRIPTION
  ***********
  The ft_access_command() function checks that the command 'cmd' exists and
  can be executed.

  This function adds the '/' prefix along with the command name to each of the
  paths contained within the PATH environment variable to check if the command
  is valid or not.

  RETURN VALUE
  ************
  - If the command is valid, returns its corresponding path necessary for its
    execution.
  - If not, return NULL;
*/

char	*ft_access_command(char **env_path, char *cmd)
{
	ssize_t	i;
	int		j;
	char	*dst;
	char	*dst2;

	i = -1;
	while (env_path[++i])
	{
		dst = ft_strjoin(ft_strjoin(env_path[i], "/", 0), cmd, 1);
		j = access(dst, F_OK);
		if (j == 0)
		{
			dst2 = ft_strndup(dst, ft_strlen(dst));
			free(dst);
			return (dst2);
		}
		free(dst);
	}
	return (NULL);
}
