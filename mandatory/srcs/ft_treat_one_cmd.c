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
  The ft_treat_one_cmd() function get only the second command passed, and only
  checks its system path. If the command is valid, it proceeds to its execution.

  RETURN VALUE
  ************
  - If the the second command is valid, the function will process the command
    and exits the program.
  - If the command is not valid or if any error occurs during its treatment and
    execution, the function sends the correspondind error message and closes
    the program.

*/

void	ft_treat_one_cmd(t_holder *holder, int argc, \
		char **argv, char **envp)
{
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_get_commands_path(holder, envp, argc - 4);
	ft_process_final(holder, envp, 0);
	ft_general_free(holder);
	exit (1);
}