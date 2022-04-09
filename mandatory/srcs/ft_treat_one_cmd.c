#include "../incs/pipex.h"

void	ft_treat_one_cmd(t_holder *holder, int argc, \
		char **argv, char **envp)
{
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_get_commands_path(holder, envp, argc - 4);
	ft_process_final(holder, envp, 0);
	ft_general_free(holder);
	exit (1);
}