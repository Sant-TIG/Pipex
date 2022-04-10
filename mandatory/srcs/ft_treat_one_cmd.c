#include "../incs/pipex.h"

/*
  TYPE
  ****
  Specific function from pipex program.

  PARAMETERS
  **********
  utils   --> the structure that contains the list of commands and their 
              system paths.
  argv    --> two-dimensional array that contains the arguments passed when
              executing the program.
  start   --> the position in the array where the first command is stored.
  cmd_nbr --> the number of commands passed when executing the program.

  DESCRIPTION
  ***********
  The ft_get_commands() function stores in a three-dimensional array each of
  the commands, along with their arguments, passed when excecuting the program.

  Each of the commands is stored in a two-dimensional array, so the command and
  its arguments are separated into different strings within the two-dimensional
  array.

  RETURN VALUE
  ************

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