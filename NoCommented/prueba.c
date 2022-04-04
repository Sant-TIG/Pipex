#include "incs/pipex_bonus.h"

int main()
{
	char	*dst;
	int i = 0;

	while (i++ < 5)
	{
		dst = get_next_line(0);
		printf("%s\n", dst);
	}
}