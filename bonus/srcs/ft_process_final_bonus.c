/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_final_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:55:59 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 20:58:22 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_process_final(t_holder *holder, char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_dup2(holder->fds->outfile_fd, STDOUT_FILENO, holder);
		ft_close(holder->fds->outfile_fd, holder);
		ft_execve(holder, envp, i);
		exit (1);
	}
	else
		waitpid(pid, NULL, 0);
}
