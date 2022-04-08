/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:10:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:29:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_holder	holder;

	holder.utils = (t_utils *)malloc(sizeof(t_utils));
	holder.fds = (t_fds *)malloc(sizeof(t_fds));
	i = -1;
	if (argc == 5)
	{
		ft_check_files(&holder, argv, 1, (size_t)argc - 1);
		ft_get_commands(holder.utils, argv, 2, (size_t)argc - 3);
		ft_get_commands_path(&holder, envp, argc - 3);
		ft_dup2(holder.fds->infile_fd, STDIN_FILENO, &holder);
		ft_close(holder.fds->infile_fd, &holder);
		while (++i < argc - 4)
			ft_process(&holder, envp, i);
		ft_process_final(&holder, envp, i);
		ft_general_free(&holder);
		return (0);
	}
	ft_general_free(&holder);
	write(1, "Invalid arguments.\n", 19);
	return (0);
}
