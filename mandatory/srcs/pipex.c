/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:10:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:29:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_holder	holder;

	holder.utils = (t_utils *)malloc(sizeof(t_utils));
	holder.fds = (t_fds *)malloc(sizeof(t_fds));
	if (argc == 5)
	{
		if (!ft_check_files(&holder, argv[1],  argv[argc - 1]))
			ft_treat_one_cmd(&holder, argc, argv, envp);
		ft_treat_multiple_cmds(&holder, argc, argv, envp);
		return (0);
	}
	ft_general_free(&holder);
	write(1, "Invalid arguments.\n", 19);
	return (0);
}
