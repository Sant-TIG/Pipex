#include "../incs/pipex.h"

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
}