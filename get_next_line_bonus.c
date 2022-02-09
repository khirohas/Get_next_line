/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 08:44:04 by khirohas          #+#    #+#             */
/*   Updated: 2022/02/09 19:14:35 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stdint.h>

static char	*update_save(char *save)
{
	char	*line;
	char	*nlptr;

	if (!ft_strchr(save, '\n'))
		return (NULL);
	line = ft_strcdup(save, '\n');
	if (line == NULL)
		return (NULL);
	nlptr = ft_strchr(save, '\n') + 1;
	ft_strlcpy(save, nlptr, ft_strlen(nlptr) + 1);
	return (line);
}

static char	*ft_read_buffer(int fd)
{
	char	*buf1;
	char	*tmp;
	char	*raw_line;
	ssize_t	read_ret;

	raw_line = NULL;
	buf1 = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf1)
		return (NULL);
	*buf1 = '\0';
	while (!ft_strchr(buf1, '\n'))
	{
		read_ret = read(fd, buf1, (size_t)BUFFER_SIZE);
		if ((read_ret <= 0))
			break ;
		buf1[read_ret] = '\0';
		tmp = ft_strcjoin(raw_line, buf1, '\0');
		free(raw_line);
		raw_line = tmp;
		if (!tmp)
			break ;
	}
	free(buf1);
	return (raw_line);
}

static char	*gnl_split(char *buf, char *save)
{
	char	*line;
	char	*nlptr;

	if (buf == NULL && save[0] == '\0')
		return (NULL);
	else if (buf == NULL || !(ft_strchr(buf, '\n')))
	{
		line = ft_strcjoin(save, buf, '\0');
		save[0] = '\0';
	}
	else
	{
		line = ft_strcjoin(save, buf, '\n');
		nlptr = (ft_strchr(buf, '\n') + 1);
		ft_strlcpy(save, nlptr, ft_strlen(nlptr) + 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	save[OPEN_MAX][(size_t)BUFFER_SIZE];
	char		*raw_line;
	char		*line;

	errno = 0;
	if ((fd < 0 || OPEN_MAX <= fd) || read(fd, save[fd], 0) != 0)
		return (NULL);
	if (ft_strchr(save[fd], '\n'))
		return (update_save(save[fd]));
	raw_line = ft_read_buffer(fd);
	if (errno != 0)
		return (NULL);
	line = gnl_split(raw_line, save[fd]);
	free(raw_line);
	return (line);
}
