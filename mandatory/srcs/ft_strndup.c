/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:09:12 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:09:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strncpy(dst, str, len + 1);
	return (dst);
}
