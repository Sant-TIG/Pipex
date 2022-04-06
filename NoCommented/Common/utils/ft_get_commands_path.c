#include "../../incs/pipex.h"

void	ft_get_commands_path(t_holder *holder, char **envp, int len)
{
	ssize_t	i;
	char	**env_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	env_path = ft_split(envp[i], ':');
	env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]) - 5);
	i = -1;
	holder->utils->cmd_path = (char **)malloc(sizeof(char *) * (len + 1));
	while (++i < len)
	{
		holder->utils->cmd_path[i] = ft_access_command(env_path, holder->utils->cmds[i][0]);
		if (!holder->utils->cmd_path[i])
		{
			ft_general_free(holder);
			ft_free_2d_str(env_path);
			write(1, "Invalid command\n", 16);
			exit (1);
		}
	}
	holder->utils->cmd_path[i] = NULL;
	ft_free_2d_str(env_path);
}