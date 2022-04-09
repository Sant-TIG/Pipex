/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:42:56 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:42:57 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*dest;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strndup("", 0));
	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strncpy(dest, &str[start], len + 1);
	free(str);
	return (dest);
}
