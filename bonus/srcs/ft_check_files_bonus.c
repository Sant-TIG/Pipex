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

int	ft_check_files(t_holder *holder, char *input_file, char *output_file)
{
	holder->fds->infile_fd = open(input_file, O_RDONLY);
	holder->fds->outfile_fd = open(output_file, \
		O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (holder->fds->infile_fd == -1)
	{
		perror("");
		return (0);
	}
	return (1);
}
