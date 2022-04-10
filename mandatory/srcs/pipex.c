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

/*
  PARAMETERS
  **********
  holder       --> the structure that contains the data structures of the
  				         program. Used here to store the fds of the files.
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

static int	ft_check_files(t_holder *holder, char *input_file, char *output_file)
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

/*
  TYPE
  ****
  Main function from pipex program.

  PARAMETERS
  **********
  argc    --> the number of arguments passed when executing the program.
  argv    --> the arguments passed when executing the program.
  envp    --> the environment variables.

  DESCRIPTION
  ***********
  The main() function creates the memory space for the data structures to be
  used during the program and checks the number of arguments passed to redirect
  the program in one direction or another.

  If the number of arguments is other than five, it frees the memory of the
  data structures and exits the program. If is equal to five it will proceed
  according the input and output files.

  If the input file doesn't exist, call the function ft_treat_one_cmd() which
  will execute just the second command. If it exists, call the function
  ft_treat_multiple_cmds() which will execute both first and second commands. 

  RETURN VALUE
  ************
  - If the number of arguments is equal to five, it will process the commands.
  - If it is other than five, send a message error and exits the program.

*/

int	main(int argc, char **argv, char **envp)
{
	t_holder	holder;

	holder.utils = (t_utils *)malloc(sizeof(t_utils));
	holder.fds = (t_fds *)malloc(sizeof(t_fds));
	if (argc == 5)
	{
		if (!ft_check_files(&holder, argv[1],  argv[argc - 1]))
			ft_treat_one_cmd(&holder, argc, argv, envp);
		ft_treat_multiple_cmds(&holder, argc, argv, envp);
		return (0);
	}
	ft_general_free(&holder);
	write(1, "Invalid arguments.\n", 19);
	return (0);
}
