/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_here_doc_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:59:08 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 20:59:32 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_insert_char(t_str **str, char c, int pos)
{
	t_str	*new_char;
	t_str	*tmp;
	
	tmp = *str;
	new_char = (t_str *)malloc(sizeof(t_str));
	if (!new_char)
		return ;
	new_char->c = c;
	if (!*str)
	{
		new_char->next = NULL;
		*str = new_char;
		return ;
	}
	if (pos == 1)
	{
		new_char->next = (*str)->next;
		*str = new_char;
		return ;
	}
	while (--pos > 1)
		tmp = tmp->next;
	new_char->next = tmp->next;
	tmp->next = new_char;
}

char *get_next_line(int fd)
{
	t_str	*str;
	t_str	*tmp;
	char	*buffer;
	char	c;
	size_t	j = 0;
	int		pos = 0;

	str = NULL;
	read(fd, &c, 1);
	while (c != '\n' && c != '\0')
	{
		ft_insert_char(&str, c, ++pos);
		//printf("%d\n\n", pos);
		read(fd, &c, 1);
	}
	if (c == '\n')
		ft_insert_char(&str, c, ++pos);
	buffer = (char *)malloc(sizeof(char) * (pos + 1));
	if (!buffer)
		return (NULL);
	tmp = str;
	while (pos--)
	{
		buffer[j++] = tmp->c;
		tmp = tmp->next;
	}
	buffer[j] = '\0';
	tmp = str;
	while (tmp)
	{
		tmp = tmp->next;
		free(str);
		str = tmp;
	}
	return (buffer);
}
/*
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(1024);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
*/


static void	ft_process_here_doc(char *delimiter, t_holder *holder)
{
	int		fd[2];
	char	*dst;

	ft_pipe(fd, holder);
	while (1)
	{
		dst = get_next_line(0);
		//printf("dst = %s delimiter = %s\n", dst, delimiter);
		if (!ft_strncmp(dst, delimiter, ft_strlen(dst) - 1))
		{
			free(dst);
			break ;
		}
		write(fd[1], dst, ft_strlen(dst));
		free(dst);
	}
	ft_close(fd[1], holder);
	ft_dup2(fd[0], STDIN_FILENO, holder);
	ft_close(fd[0], holder);
}

void	ft_treat_here_doc_case(t_holder *holder, \
		int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	holder->fds->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_APPEND | O_CREAT, 0660);
	if (holder->fds->outfile_fd == -1)
	{
		write (1, "Invalid file\n", 13);
		exit (1);
	}
	ft_get_commands(holder->utils, argv, 3, (size_t)argc - 4);
	ft_get_commands_path(holder, envp, argc - 4);
	ft_process_here_doc(argv[2], holder);
	while (++i < argc - 5)
		ft_process(holder, envp, i);
	ft_process_final(holder, envp, i);
	ft_general_free(holder);
	exit (1);
}
