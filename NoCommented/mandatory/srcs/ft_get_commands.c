/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:07:00 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:07:05 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_get_commands(t_utils *utils, char **argv, size_t start, size_t len)
{
	ssize_t	i;

	i = -1;
	utils->cmds = (char ***)malloc(sizeof(char **) * (len + 1));
	if (!utils->cmds)
		return ;
	while (len--)
		utils->cmds[++i] = ft_split(argv[start++], ' ');
	utils->cmds[++i] = NULL;
}
