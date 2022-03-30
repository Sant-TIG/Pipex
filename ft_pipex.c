#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}


char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, str, len + 1);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strndup("", 0));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, &s[start], len + 1);
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = dstl;
	if (dstl >= dstsize)
		return (dstsize + srcl);
	while (dstl < dstsize - 1 && *src)
		*(dst + dstl++) = *src++;
	*(dst + dstl) = '\0';
	return (i + srcl);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1, s1_len + 1);
	ft_strlcat(&dest[s1_len], s2, s2_len + 1);
	return (dest);
}

static char	*ft_splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

static char	**ft_process_string(char **dest, const char *str, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			if (str[i] == c || i == ft_strlen(str))
				dest[p1++] = ft_splitdup(str, start, i);
		}
		while (str[i] == c && str[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

static size_t	ft_line_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		count++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**dest;

	if (!str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		return (NULL);
	ft_process_string(dest, str, c);
	return (dest);
}

int	ft_strstr(char *str, char *str1)
{
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str != *str1)
			str++;
		while (*str && *str1 && *str == *str1)
		{
			str++;
			str1++;
			if (!*str1)
				return (1);
		}
		return (0);
	}
	return (0);
}

char	*ft_access(char **cmd_path)
{
	int		j;
	char	*dst;

	while(*cmd_path)
	{
		j = access(*cmd_path, F_OK);
		if (j == 0)
			return (ft_strndup(*cmd_path, ft_strlen(*cmd_path)));
		cmd_path++;
	}
	return (NULL);
}

void ft_free(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fds;
	char	*env;
	char	**split_env;
	char	**cmd1_paths;
	char	**cmd2_paths;
	char	*cmd1_path;
	char	*cmd2_path;
	int		pid;
	int		i = 0;

	if (argc == 5)
	{
		fds.infile_fd = open(argv[1], O_RDONLY);
		fds.outfile_fd = open(argv[4], O_WRONLY);
		if (fds.infile_fd == -1 || fds.outfile_fd == -1)
		{
			write (1, "Invalid file\n", 13);
			return (0);
		}
		while (!ft_strstr(*envp, "PATH="))
			envp++;
		split_env = ft_split(*envp, ':');
		while (split_env[i])
			i++;
		cmd1_paths = (char **)malloc(sizeof(char *) * i + 1);
		cmd2_paths = (char **)malloc(sizeof(char *) * i + 1);
		if (!cmd1_paths || !cmd2_paths)
		{
			ft_free(split_env);
			return (0);
		}
		split_env[0] = ft_substr(split_env[0], 5, ft_strlen(split_env[0]) - 5);
		i = -1;
		while (split_env[++i])
		{
			cmd1_paths[i] = ft_strjoin(ft_strjoin(split_env[i], "/"), argv[2]);
			cmd2_paths[i] = ft_strjoin(ft_strjoin(split_env[i], "/"), argv[3]);
		}
		cmd1_paths[i] = NULL;
		cmd2_paths[i] = NULL;
		cmd1_path = ft_access(cmd1_paths);
		cmd2_path = ft_access(cmd2_paths);
		printf("%s\n%s\n", cmd1_path, cmd2_path);
		if (!cmd1_path || !cmd2_path)
		{
			ft_free(cmd1_paths);
			ft_free(cmd2_paths);
			write(1, "Invalid command\n", 16);
			return (0);
		}
		pipe(fds.fd1);
		pid = fork();
		if (pid == 0)
		{
			dup2(fds.infile_fd, STDIN_FILENO);
			close(fds.infile_fd);
			close(fds.fd1[0]);
			dup2(fds.fd1[1], STDOUT_FILENO);
			close(fds.fd1[1]);
			execve(cmd1_path, argv[2], split_env);//para el execve necesitamos el path del comando que vamos a utilizar, el arrays bidimensional del comando con sus argumentos, y el array del environtemnt.
		}
		else
		{
			close(fds.fd1[1]);
			pid = fork;
			if (pid == 0)
			{
				dup2(fds.fd1[0], STDIN_FILENO);
				close(fds.fd1[0]);
				dup2(fds.outfile_fd, STDOUT_FILENO);
				close(fds.outfile_fd);
				execve(cmd2_path, argv[4], split_env);
			}
			else
				close (fds.fd1[0]);
		}
		/*i = -1;
		while (cmd1_paths[++i])
			printf("%s\n\n%s\n\n", cmd1_paths[i], cmd2_paths[i]);*/
		return (0);
	}
	write(1, "Invalid arguments.\n", 19);
	return (0);
}