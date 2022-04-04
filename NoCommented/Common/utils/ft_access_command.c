#include "../../incs/pipex.h"

char	*ft_access_command(char **env_path, char *cmd)
{
	ssize_t	i;
	int		j;
	char	*dst;

	i = -1;
	while (env_path[++i])
	{
		j = access(ft_strjoin(ft_strjoin(env_path[i], "/"), cmd), F_OK);
		if (j == 0)
		{
			dst = ft_strndup(ft_strjoin(ft_strjoin(env_path[i], "/"), cmd), ft_strlen(ft_strjoin(ft_strjoin(env_path[i], "/"), cmd)));
			return(dst);
		}
	}
	return (NULL);
}