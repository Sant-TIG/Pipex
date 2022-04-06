#include "../incs/pipex.h"

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
	waitpid(pid, NULL, 0);
}

void	ft_process_here_doc(char *delimiter, t_holder *holder)
{
	int		fd[2];
	pid_t	pid;
	char	*dst;

	if (pipe(fd) == -1)
	{
		printf("Pipe error\n");
		free(delimiter);
		exit (1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			dst = get_next_line(0);
			if (!ft_strncmp(dst, delimiter, ft_strlen(delimiter) - 1))
			{
				free(dst);
				break ;
			}
			write(fd[1], dst, ft_strlen(dst));
			free(dst);
		}
		ft_general_free(holder);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	waitpid(pid, NULL, 0);
}


void	ft_treat_here_doc_case(t_holder *holder, int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	holder->fds->outfile_fd = open(argv[argc - 1], O_WRONLY|O_APPEND);
	if (holder->fds->outfile_fd == -1)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_print_commands(holder->utils);
	ft_get_commands_path(holder, envp, argc - 4);
	ft_print_commands_path(holder->utils);
	ft_process_here_doc(argv[2], holder);
	while (++i < argc - 5)
		ft_process(holder, envp, i);
	ft_dup2(holder->fds->outfile_fd, STDOUT_FILENO, holder);
	ft_close(holder->fds->outfile_fd, holder);
	ft_execve(holder, envp, i);
	ft_general_free(holder);
	exit (1);
}

void	ft_multiple_cmds(t_holder *holder, int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	ft_check_files(holder->fds, argv, 1, (size_t)argc - 1);
	ft_get_commands(holder->utils, argv, 2, (size_t)argc - 3);
	//ft_print_commands(utils);
	ft_get_commands_path(holder, envp, argc - 3);
	//ft_print_commands_path(utils);
	ft_dup2(holder->fds->infile_fd, STDIN_FILENO, holder);
	ft_close(holder->fds->infile_fd, holder);
	while (++i < argc - 4)
		ft_process(holder, envp, i);
	ft_dup2(holder->fds->outfile_fd, STDOUT_FILENO, holder);
	ft_close(holder->fds->outfile_fd, holder);
	ft_execve(holder, envp, i);
	ft_general_free(holder);
	exit (1);
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