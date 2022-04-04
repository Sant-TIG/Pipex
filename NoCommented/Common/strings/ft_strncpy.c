#include "../../incs/pipex.h"

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