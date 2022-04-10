/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:07:21 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:07:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  TYPE
  ****
  Specific function from pipex program.

  PARAMETERS
  **********
  holder  --> the structure that contains the data structures of the program.
  envp    --> two-dimensional array that stores the environment variables.
  cmd_nbr --> the number of commands passed when execute the program.

  DESCRIPTION
  ***********
  The ft_get_commands_path() function checks that each command entered is valid,
  and therefore executable, and returns its corresponding system path. This path
  is acquired by the ft_accesss_command() functions from the multiple
  paths stroed within the PATH environment variable.

  At first,it looks for the PATH variable within the environment variables
  stored in 'envp'. Then, it stores in a two-dimensional array each of the paths
  stored in them, separated by the ':' character. 
  
  By this way the function can check if the directory of each command exists in
  each of the paths and check if it is valid or not.

  RETURN VALUE
  ************
  - If all the commands are valid, it stores int he utils structure the system
    path of each one.
  - If any command is not valid, it free all memory allocated on the head and
    closes the program.
*/

void	ft_get_commands_path(t_holder *holder, char **envp, int cmd_nbr)
{
	ssize_t	i;
	char	**env_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	env_path = ft_split(envp[i], ':');
	env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]) - 5);
	i = -1;
	holder->utils->cmd_path = (char **)malloc(sizeof(char *) * (cmd_nbr + 1));
	while (++i < cmd_nbr)
	{
		holder->utils->cmd_path[i] = ft_access_command(env_path, \
				holder->utils->cmds[i][0]);
		if (!holder->utils->cmd_path[i])
		{
			ft_general_free(holder);
			ft_free_2d_str(env_path);
			write(1, "Invalid command\n", 16);
			exit (1);
		}
	}
	holder->utils->cmd_path[i] = NULL;
	ft_free_2d_str(env_path);
}
