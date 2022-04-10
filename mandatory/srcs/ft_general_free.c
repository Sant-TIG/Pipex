/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:06:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:06:54 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*
  TYPE
  ****
  Specific function for the pipex program.

  PARAMETERS
  **********
  holder --> the structure that contains the data structures of the program.

  DESCRIPTION
  ***********
  The ft_general_free() function checks if the utils structure contains data
  stored in it to proceed to free them. It also frees the memory space of
  the structures stored in holder.
*/

void	ft_general_free(t_holder *holder)
{
	if (holder->utils->cmds)
		ft_free_3d_str(holder->utils->cmds);
	if (holder->utils->cmd_path)
		ft_free_2d_str(holder->utils->cmd_path);
	free(holder->utils);
	free(holder->fds);
}
