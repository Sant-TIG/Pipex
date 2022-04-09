/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:39:18 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:39:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2, int n)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	ft_strncpy(dest, s1, s1_len + 1);
	ft_strlcat(&dest[s1_len], s2, s2_len + 1);
	if (n == 1)
		free((char *)s1);
	return (dest);
}
