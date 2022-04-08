/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_command_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:34:00 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:34:20 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

char	*ft_access_command(char **env_path, char *cmd)
{
	ssize_t	i;
	int		j;
	char	*dst;
	char	*dst2;

	i = -1;
	while (env_path[++i])
	{
		dst = ft_strjoin(ft_strjoin(env_path[i], "/", 0), cmd, 1);
		j = access(dst, F_OK);
		if (j == 0)
		{
			dst2 = ft_strndup(dst, ft_strlen(dst));
			free(dst);
			return (dst2);
		}
		free(dst);
	}
	return (NULL);
}
