#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int		main(void)
{
	int		fd = open("41_no_nl", O_RDONLY);
	char *ret;
	size_t i = 0;
	size_t n = 1;

	while (i < n)
	{
		ret = get_next_line(fd);
		printf("ret:%s", ret);
		printf("ret:%ld", ft_strlen(ret));
		printf("cmp:%i", strcmp(ret, "01234567890123456789012345678901234567890"));
		free(ret);
		i++;
	}
	return (0);
}
