/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:07:00 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:07:05 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  TYPE
  ****
  Specific function from pipex program.

  PARAMETERS
  **********
  utils   --> the structure that contains the list of commands and their 
              system paths.
  argv    --> two-dimensional array that contains the arguments passed when
              executing the program.
  start   --> the position in the array where the first command is stored.
  cmd_nbr --> the number of commands passed when executing the program.

  DESCRIPTION
  ***********
  The ft_get_commands() function stores in a three-dimensional array each of
  the commands, along with their arguments, passed when excecuting the program.

  Each of the commands is stored in a two-dimensional array, so the command and
  its arguments are separated into different strings within the two-dimensional
  array.

  RETURN VALUE
  ************

*/

void	ft_get_commands(t_utils *utils, char **argv, size_t start, size_t cmd_nbr)
{
	ssize_t	i;

	i = -1;
	utils->cmds = (char ***)malloc(sizeof(char **) * (cmd_nbr + 1));
	if (!utils->cmds)
		return ;
	while (cmd_nbr--)
		utils->cmds[++i] = ft_split(argv[start++], ' ');
	utils->cmds[++i] = NULL;
}
