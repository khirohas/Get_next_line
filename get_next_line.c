/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 08:44:04 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/25 08:44:04 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifdef BUFFER_SIZE

char	*get_next_line(int fd)
{
	static char	*save;
	static char		*nl;
	size_t		len_save;
	char		buf[BUFFER_SIZE + 1];
	char		*line;

	//nl = NULL;
	if (save)
	{
		nl = ft_strchr(save, '\n');
		len_save = ft_strlen(save);
	}
	if (nl)
	{
		line = malloc((nl - save) + 2);
		ft_memmove(line, save, (nl - save + 1));
		line[nl - save + 1] = '\0';
		save = nl + 1;
		return (line);
	}
	else
	{
	//	buf = read_buffer(fd);
		read (fd, buf, BUFFER_SIZE);
		if (!save)
			len_save = 0;
		buf[BUFFER_SIZE] = '\0';
		printf("%s\n", buf);
		nl = ft_strchr(buf, '\n');
		line = malloc(len_save + (nl - buf) + 2);
		if (save)
			ft_memmove(line, save, len_save);
		ft_memmove(line + len_save, buf, nl - buf + 1);
		save = nl + 1;
		return (line);
	}
}

/*
char	*get_next_line(int fd)
{
	static char	*save;
	static char		*nl;
	size_t		len_save;
	char		*buf;
	char		*line;

	//nl = NULL;
	if (save)
	{
		nl = ft_strchr(save, '\n');
		len_save = ft_strlen(save);
	}
	if (nl)
	{
		line = malloc((nl - save) + 2);
		ft_memmove(line, save, (nl - save + 1));
		line[nl - save + 1] = '\0';
		save = nl + 1;
		return (line);
	}
	else
	{
		buf = read_buffer(fd);
		if (!save)
			len_save = 0;
		nl = ft_strchr(buf, '\n');
		line = malloc(len_save + (nl - buf) + 2);
		ft_memmove(line, save, len_save);
		ft_memmove(line + len_save, buf, nl - buf + 1);
		line[len_save + nl - buf + 1] = '\0';
		save = nl + 1;
		free(buf);
		return (line);
	}
}
*/
#endif
