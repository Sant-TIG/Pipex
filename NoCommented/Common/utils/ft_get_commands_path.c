#include "../../incs/pipex.h"

void	ft_get_commands_path(t_utils *utils, char **envp, int len)
{
	ssize_t	i;
	char	**env_path;

	i = 0;
	/*1º. Identificar la variable PATH dentro de las variables de entorno almacenadas en envp y quedarnos con su posicion para crear una copia bidimensional separadas por el caracter ':'*/
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	env_path = ft_split(envp[i], ':');
	/*2º. Eliminar la cadena PATH= de la primera cadena*/
	env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]) - 5);
	i = -1;
	utils->cmd_path = (char **)malloc(sizeof(char *) * (len + 1));
	while (++i < len)
	{
		utils->cmd_path[i] = ft_access_command(env_path, utils->cmds[i][0]);
		
		if (!utils->cmd_path[i])
		{
			write(1, "Invalid command\n", 16);
			exit (0);
		}
	}
	utils->cmd_path[i] = NULL;
}