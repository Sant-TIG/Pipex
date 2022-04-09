/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:38:54 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:38:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

size_t	ft_get_char_len(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i] != c)
		i++;
	return (i + 1);
}

size_t	ft_check_char(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str && *str != c)
		str++;
	return (*str == c);
}
