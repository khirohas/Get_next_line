#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int		main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	char *ret;
	size_t i = 0;
	size_t n = 12;

	while (i < n)
	{
		ret = get_next_line(fd);
		printf("ret:%s", ret);
		free(ret);
		i++;
	}
	return (0);
}
