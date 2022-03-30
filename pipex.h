#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_fd
{
	int	infile_fd;
	int	outfile_fd;
	int	fd1[2];
	int	fd2[2];
}	t_fd;

#endif