#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
void end(void)
{
	if (system("leaks -q a.out > /dev/null"))
		system("leaks -q a.out");
}

int		main(void)
{
	int		fd;
	char *ret = "42";
	//size_t ret_size;
	size_t i = 0;
	size_t n = 4;

	fd = open("text", O_RDONLY);
	//fd = 0;

	while (ret != NULL)
	{
		ret = get_next_line(fd);
		printf("ret[%ld]:%s", i, ret);
		//write(1, ret, ret_size);
		//printf("ret_len:[%ld]\n", ft_strlen(ret));
		//printf("cmp:[%i]\n", strcmp(ret, "01234567890123456789012345678901234567890"));
		free(ret);
		i++;
	}
	printf("\nerrno:%d\n", errno);
	end();
	return (0);
}
