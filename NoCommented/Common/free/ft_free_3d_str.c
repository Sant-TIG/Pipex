#include "../../incs/pipex.h"

void	ft_free_3d_str(char ***str)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			free(str[i][j]);
		free(str[i][j]);
		free(str[i]);
	}
	free(str);
}