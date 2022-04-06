#include "../../incs/pipex_bonus.h"

void	ft_general_free_bonus(t_holder *holder)
{
	if (holder->utils->cmds)
		ft_free_3d_str(holder->utils->cmds);
	if (holder->utils->cmd_path)
		ft_free_2d_str(holder->utils->cmd_path);
	free(holder->utils);
	free(holder->fds);
}