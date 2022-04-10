/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:55:47 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 20:55:48 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

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
