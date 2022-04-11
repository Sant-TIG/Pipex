/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:09:36 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 19:09:37 by sperez-p         ###   ########.fr       */
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
  The ft_process() function is responsible for creating a pipe and a process
  for each command. By this way, the child process executes the command and
  redirects its output to the writing end of the pipe. Then the parent
  process redirects the content of the pipe to the standard input so that it
  can be used by the next command.

  RETURN VALUE
  ************
  - If no error occurs, run the command.
  - If not, send the corresponding message error and exits the process.
*/

void	ft_process(t_holder *holder, char **envp, size_t i)
{
	pid_t	pid;

	ft_pipe(holder->fds->fd, holder);
	pid = fork();
	if (pid == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
	if (pid == 0)
	{
		ft_close(holder->fds->fd[0], holder);
		ft_dup2(holder->fds->fd[1], STDOUT_FILENO, holder);
		ft_close(holder->fds->fd[1], holder);
		ft_execve(holder, envp, i);
		exit (1);
	}
	else
	{
		ft_close(holder->fds->fd[1], holder);
		ft_dup2(holder->fds->fd[0], STDIN_FILENO, holder);
		ft_close(holder->fds->fd[0], holder);
	}
	waitpid(pid, NULL, 0);
}
