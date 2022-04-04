#include "../incs/pipex_bonus.h"

void	ft_print_commands(t_utils *utils)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (utils->cmds[++i])
	{
		j = -1;
		printf("%ldº 2d string\n", i);
		while (utils->cmds[i][++j])
			printf("%s\n", utils->cmds[i][j]);
	}
}

void	ft_print_commands_path(t_utils *utils)
{
	ssize_t	i;

	i = -1;
	while (utils->cmd_path[++i])
		printf("%ldº string = %s\n", i, utils->cmd_path[i]);
}


void	ft_process(t_utils *utils, char **envp, size_t i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		write(1, "Pipe error\n", 11);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(utils->cmd_path[i], utils->cmds[i], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	ft_process_here_doc(char *delimiter)
{
	int		fd[2];
	pid_t	pid;
	char	*dst[1024];
	int i = -1;
	int j = -1;

	while (++i > -1)
	{
		dst[i] = get_next_line(0);
		if (!ft_strncmp(dst[i], delimiter, ft_strlen(delimiter) - 1))
			break ;
	}
	dst[i] = NULL;
	if (pipe(fd) == -1)
	{
		printf("Pipe error\n");
		exit (1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (++j < i)
			write(fd[1], dst[j], ft_strlen(dst[j]));
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	ft_treat_here_doc_case(t_holder *holder, int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	holder->fds->outfile_fd = open(argv[argc - 1], O_WRONLY);
	if (holder->fds->outfile_fd == -1)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	//ft_print_commands(holder->utils);
	ft_get_commands_path(holder->utils, envp, argc - 4);
	//ft_print_commands_path(holder->utils);
	ft_process_here_doc(argv[2]);
	while (++i < argc - 5)
		ft_process(holder->utils, envp, i);
	dup2(holder->fds->outfile_fd, STDOUT_FILENO);
	close(holder->fds->outfile_fd);
	execve(holder->utils->cmd_path[i], holder->utils->cmds[i], envp);
	exit (0);
}

void	ft_multiple_cmds(t_holder *holder, int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	ft_check_files(holder->fds, argv, 1, (size_t)argc - 1);
	ft_get_commands(holder->utils, argv, 2, (size_t)argc - 3);
	//ft_print_commands(utils);
	ft_get_commands_path(holder->utils, envp, argc - 3);
	ft_print_commands_path(holder->utils);
	dup2(holder->fds->infile_fd, STDIN_FILENO);
	close(holder->fds->infile_fd);
	while (++i < argc - 4)
		ft_process(holder->utils, envp, i);
	dup2(holder->fds->outfile_fd, STDOUT_FILENO);
	close(holder->fds->outfile_fd);
	execve(holder->utils->cmd_path[i], holder->utils->cmds[i], envp);
	exit (0);
}

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
			ft_multiple_cmds(&holder, argc, argv, envp);
	}
	write(1, "Invalid arguments.\n", 19);
	return (0);
}