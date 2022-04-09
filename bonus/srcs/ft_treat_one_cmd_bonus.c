#include "../incs/pipex_bonus.h"
/*
static void	ft_print_commands(t_utils *utils)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (utils->cmds[++i])
	{
		j = -1;
		printf("%ldº 2d string\n", i);
		while (utils->cmds[i][++j])
			printf("%s\n", utils->cmds[i][j]);
	}
}

static void	ft_print_commands_path(t_utils *utils)
{
	ssize_t	i;

	i = -1;
	while (utils->cmd_path[++i])
		printf("%ldº string = %s\n", i, utils->cmd_path[i]);
}*/

void	ft_treat_one_cmd(t_holder *holder, int argc, \
		char **argv, char **envp)
{
	int	i;

	i = -1;
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_get_commands_path(holder, envp, argc - 4);
	while (++i < argc - 5)
		ft_process(holder, envp, i);
	ft_process_final(holder, envp, i);
	ft_general_free(holder);
	exit (1);
}