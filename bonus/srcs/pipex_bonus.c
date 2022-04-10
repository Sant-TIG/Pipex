/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:31:46 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 20:59:47 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_holder	holder;

	holder.utils = (t_utils *)malloc(sizeof(t_utils));
	holder.fds = (t_fds *)malloc(sizeof(t_fds));
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
			ft_treat_here_doc_case(&holder, argc, argv, envp);
		else
			ft_treat_multiple_cmds(&holder, argc, argv, envp);
	}
	ft_general_free(&holder);
	write(1, "Invalid arguments.\n", 19);
	return (0);
}
