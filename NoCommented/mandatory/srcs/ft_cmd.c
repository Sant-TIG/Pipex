/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:09:20 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 19:09:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_execve(t_holder *holder, char **envp, int i)
{
	if (execve(holder->utils->cmd_path[i], holder->utils->cmds[i], envp) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_close( int fd, t_holder *holder)
{
	if (close(fd) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_dup2(int fd1, int fd2, t_holder *holder)
{
	if (dup2(fd1, fd2) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_pipe(int *fd, t_holder *holder)
{
	if (pipe(fd) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}
