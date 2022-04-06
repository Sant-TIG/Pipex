#include "../../incs/pipex.h"

void	ft_free_2d_str(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}