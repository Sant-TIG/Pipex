/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:34:26 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:35:28 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_check_files(t_holder *holder, char **argv, \
		size_t in_pos, size_t out_pos)
{
	holder->fds->infile_fd = open(argv[in_pos], O_RDONLY);
	holder->fds->outfile_fd = open(argv[out_pos], \
	O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (holder->fds->infile_fd == -1 || holder->fds->outfile_fd == -1)
	{
		free(holder->utils);
		free(holder->fds);
		write (1, "Invalid file\n", 13);
		exit (1);
	}
}
