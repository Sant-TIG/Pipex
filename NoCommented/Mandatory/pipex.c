#include "../incs/pipex.h"

void	ft_print_commands(t_utils utils)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (utils.cmds[++i])
	{
		j = -1;
		printf("%ldº 2d string\n", i);
		while (utils.cmds[i][++j])
			printf("%s\n", utils.cmds[i][j]);
	}
}

void	ft_print_commands_path(t_utils utils)
{
	ssize_t	i;

	i = -1;
	while (utils.cmd_path[++i])
		printf("%ldº string = %s\n", i, utils.cmd_path[i]);
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
/*
void	ft_process_last_child(t_fds *fds, t_utils *utils, char **envp, size_t i)
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
}*/

int	main(int argc, char **argv, char **envp)
{
	t_fds	fds;
	t_utils	utils;
	int		i;

	i = -1;
	if (argc == 5)
	{
		ft_check_files(&fds, argv, 1, (size_t)argc - 1);
		ft_get_commands(&utils, argv, 2, (size_t)argc - 3);
		//ft_print_commands(utils);
		ft_get_commands_path(&utils, envp, argc - 3);
		ft_print_commands_path(utils);
		dup2(fds.infile_fd, STDIN_FILENO);
		close(fds.infile_fd);
		while (++i < argc - 4)
			ft_process(&utils, envp, i);
		dup2(fds.outfile_fd, STDOUT_FILENO);
		close(fds.outfile_fd);
		execve(utils.cmd_path[i], utils.cmds[i], envp);
		return (0);
	}
	write(1, "Invalid arguments.\n", 19);
	return (0);
}