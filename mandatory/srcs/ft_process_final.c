/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:09:45 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 19:09:46 by sperez-p         ###   ########.fr       */
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

void	ft_process_final(t_holder *holder, char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_dup2(holder->fds->outfile_fd, STDOUT_FILENO, holder);
		ft_close(holder->fds->outfile_fd, holder);
		ft_execve(holder, envp, i);
	}
	else
		waitpid(pid, NULL, 0);
}
