/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:04:48 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/08 10:57:11 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  PARAMETERS
  **********
  holder       --> the structure that contains the data structures of the
  				   program. Used here to store the file descriptors of the files.
  input_file   --> the path of the input file
  output_file  --> the path of the output file

  DESCRIPTION
  ***********
  The ft_check_files() function checks that the input file can be opened and
  opens or creates the output file.

  RETURN VALUE
  ************
  - One if there is no problem opening the input file.
  - Zero if there is a problem opening the input file.

*/

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
