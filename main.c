#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int		main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	size_t	i = 3;
	while (i > 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}

}
