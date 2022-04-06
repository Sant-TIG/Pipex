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

void	ft_execve(t_holder *holder, char **envp, int i)
{
	if (execve(holder->utils->cmd_path[i], holder->utils->cmds[i], envp) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_close( int fd, t_holder *holder)
{
	if (close(fd) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_dup2(int fd1, int fd2, t_holder *holder)
{
	if (dup2(fd1, fd2) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_pipe(int *fd, t_holder *holder)
{
	if (pipe(fd) == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
}

void	ft_process(t_holder *holder, char **envp, size_t i)
{
	pid_t	pid;
	int		fd[2];

	ft_pipe(fd, holder);
	pid = fork();
	if (pid == -1)
	{
		ft_general_free(holder);
		perror("");
		exit (1);
	}
	if (pid == 0)
	{
		ft_close(fd[0], holder);
		ft_dup2(fd[1], STDOUT_FILENO, holder);
		ft_close(fd[1], holder);
		ft_execve(holder, envp, i);
		exit (1);
	}
	else
	{
		ft_close(fd[1], holder);
		ft_dup2(fd[0], STDIN_FILENO, holder);
		ft_close(fd[0], holder);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_holder	holder;

	holder.utils = (t_utils *)malloc(sizeof(t_utils));
	holder.fds = (t_fds *)malloc(sizeof(t_fds));
	i = -1;
	if (argc == 5)
	{
		ft_check_files(holder.fds, argv, 1, (size_t)argc - 1);
		ft_get_commands(holder.utils, argv, 2, (size_t)argc - 3);
		//ft_print_commands(utils);
		ft_get_commands_path(&holder, envp, argc - 3);
		//ft_print_commands_path(utils);
		ft_dup2(holder.fds->infile_fd, STDIN_FILENO, &holder);
		ft_close(holder.fds->infile_fd, &holder);
		while (++i < argc - 4)
			ft_process(&holder, envp, i);
		ft_dup2(holder.fds->outfile_fd, STDOUT_FILENO, &holder);
		ft_close(holder.fds->outfile_fd, &holder);
		ft_execve(&holder, envp, i);
		ft_general_free(&holder);
		exit (1);
	}
	write(1, "Invalid arguments.\n", 19);
	return (0);
}