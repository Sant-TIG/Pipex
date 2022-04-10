/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:08:59 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/07 16:09:00 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	if (len == 0)
		return (dst);
	while (*src && --len)
		*dst++ = *src++;
	while (--len)
		*dst++ = '\0';
	*dst = '\0';
	return (dst);
}
