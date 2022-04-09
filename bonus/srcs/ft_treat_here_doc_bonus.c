/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_here_doc_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:59:08 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 20:59:32 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

static void	ft_process_here_doc(char *delimiter, t_holder *holder)
{
	int		fd[2];
	char	*dst;

	ft_pipe(fd, holder);
	while (1)
	{
		dst = get_next_line(0);
		if (!ft_strncmp(dst, delimiter, ft_strlen(delimiter)))
		{
			free(dst);
			break ;
		}
		write(fd[1], dst, ft_strlen(dst));
		free(dst);
	}
	ft_close(fd[1], holder);
	ft_dup2(fd[0], STDIN_FILENO, holder);
	ft_close(fd[0], holder);
}

void	ft_treat_here_doc_case(t_holder *holder, \
		int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	holder->fds->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_APPEND | O_CREAT, 0660);
	if (holder->fds->outfile_fd == -1)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_get_commands_path(holder, envp, argc - 4);
	ft_process_here_doc(argv[2], holder);
	while (++i < argc - 5)
		ft_process(holder, envp, i);
	ft_process_final(holder, envp, i);
	ft_general_free(holder);
	exit (1);
}
