/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:39:25 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:39:26 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = dstl;
	if (dstl >= dstsize)
		return (dstsize + srcl);
	while (dstl < dstsize - 1 && *src)
		*(dst + dstl++) = *src++;
	*(dst + dstl) = '\0';
	return (i + srcl);
}
