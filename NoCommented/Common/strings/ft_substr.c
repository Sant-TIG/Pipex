#include "../../incs/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strndup("", 0));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strncpy(dest, &s[start], len + 1);
	return (dest);
}