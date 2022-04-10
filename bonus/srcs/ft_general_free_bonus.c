/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_free_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:36:00 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:36:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_general_free(t_holder *holder)
{
	if (holder->utils->cmds)
		ft_free_3d_str(holder->utils->cmds);
	if (holder->utils->cmd_path)
		ft_free_2d_str(holder->utils->cmd_path);
	free(holder->utils);
	free(holder->fds);
}
