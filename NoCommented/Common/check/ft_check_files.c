#include "../../incs/pipex.h"

void	ft_check_files(t_fds *fds, char **argv, size_t in_pos, size_t out_pos)
{
	fds->infile_fd = open(argv[in_pos], O_RDONLY);
	fds->outfile_fd = open(argv[out_pos], O_WRONLY);
	if (fds->infile_fd == -1 || fds->outfile_fd == -1)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
}