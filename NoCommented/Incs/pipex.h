#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_fds
{
	int	infile_fd;
	int	outfile_fd;
	int	fd[2];
}	t_fds;

typedef	struct s_utils
{
	char	**env_path;
	char	***cmds;
	char	**cmd_path;

}	t_utils;

/* CHECK FUNCTIONS */

void	ft_check_files(t_fds *fds, char **argv, size_t in_pos, size_t out_pos);

/* STRINGS FUNCTIONS */

char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *str, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* UTILS FUNCTIONS */

void	ft_get_commands(t_utils *utils, char **argv, size_t start, size_t len);
char	*ft_access_command(char **env_path, char *cmd);
void	ft_get_commands_path(t_utils *utils, char **envp, int len);

#endif