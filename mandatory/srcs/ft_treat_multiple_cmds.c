#include "../incs/pipex.h"

/*
  TYPE
  ****
  Specific function from pipex program.

  PARAMETERS
  **********
  holder  --> the structure that contains the data structures of the program.
  argc    --> the number of arguments passed when executing the program.
  argv    --> the arguments passed when executing the program.
  envp    --> the environment variables.

  DESCRIPTION
  ***********
  The ft_treat_multiple_cmds() function gets all the passed commands and then
  checks theis sustem paths. If any command is not valid, it frees all memory
  allocated so far and exits the program.

  If all commands are valid, it first duplicates the content of the input file
  to standard output so that it can be used by the first commands if necessary.
  
  Then, call the ft_process() function which will execute each command, except
  the last one, and redirect its output to the read end of pipe that connects
  it to the next command, so that it can be used as standard input in the next
  ft_process() call.

  Since the last command has to redirect its output to the output file, there
  is no need to generate a pipe for this process. So its just redirects its
  output to the output file, executes the command, frees the memory used so far,
  and exits the program. 

  RETURN VALUE
  ************
  - If all commands are valid, the function will process them, frees the memory
    used so far and exits the program.
  - If one of the commmands is not valid or if any error occurs durinf its
    treatment, the function sends the corresponding error message and closes
    the program.

*/

void	ft_treat_multiple_cmds(t_holder *holder, int argc, \
		char **argv, char **envp)
{
	int	i;

	i = -1;
	ft_get_commands(holder->utils, argv, 2, (size_t)argc - 3);
	ft_get_commands_path(holder, envp, argc - 3);
	ft_dup2(holder->fds->infile_fd, STDIN_FILENO, holder);
	ft_close(holder->fds->infile_fd, holder);
	while (++i < argc - 4)
		ft_process(holder, envp, i);
	ft_process_final(holder, envp, i);
	ft_general_free(holder);
  exit (1);
}