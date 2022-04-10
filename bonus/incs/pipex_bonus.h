/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:29:55 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:31:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# define BUFFER_SIZE 1

typedef struct s_str
{
	char	c;
	struct s_str	*next;
}	t_str;

typedef struct s_fds
{
	int	infile_fd;
	int	outfile_fd;
	int	fd[2];
}	t_fds;

typedef struct s_utils
{
	char	***cmds;
	char	**cmd_path;

}	t_utils;

typedef struct s_holder
{
	t_fds	*fds;
	t_utils	*utils;
}	t_holder;

/* CHECK FUNCTIONS */

int	ft_check_files(t_holder *holder, char *input_file, char *output_file);

/* FREE UTILS */

void	ft_free_3d_str(char ***str);
void	ft_free_2d_str(char **str);
void	ft_general_free(t_holder *holder);

/* STRINGS FUNCTIONS */

char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2, int n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *str, size_t len);
char	*ft_substr(char *str, unsigned int start, size_t len);

/* UTILS FUNCTIONS */

void	ft_get_commands(t_utils *utils, char **argv, size_t start, size_t len);
char	*ft_access_command(char **env_path, char *cmd);
void	ft_get_commands_path(t_holder *holder, char **envp, int len);
void	ft_process(t_holder *holder, char **envp, size_t i);
void	ft_treat_here_doc_case(t_holder *holder, int argc, char **argv, \
	char **envp);
void	ft_process_final(t_holder *holder, char **envp, int i);
void	ft_pipe(int *fd, t_holder *holder);
void	ft_dup2(int fd1, int fd2, t_holder *holder);
void	ft_close( int fd, t_holder *holder);
void	ft_execve(t_holder *holder, char **envp, int i);

/* GNL FUNCTIONS */

size_t	ft_check_char(const char *str, int c);
size_t	ft_get_char_len(const char *str, int c);

void	ft_treat_one_cmd(t_holder *holder, int argc, char **argv, char **envp);
void	ft_treat_multiple_cmds(t_holder *holder, int argc, char **argv, char **envp);

#endif
