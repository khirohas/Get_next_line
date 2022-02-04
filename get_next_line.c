/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 08:44:04 by khirohas          #+#    #+#             */
/*   Updated: 2022/02/05 00:05:51 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef BUFFER_SIZE
static char	*check_save(char *save)
{
	char	*line;
	char	*nlptr;

	if (!(line = ft_strcdup(save, '\n')))
		return (NULL);
	nlptr = (ft_strchr(save, '\n') + 1);
	ft_strlcpy(save, nlptr, ft_strlen(nlptr) + 1);
	return (line);
}

static char	*ft_read_buffer(int fd)
{
	char	*buf1;
	char	*buf2;
	char	*raw_line;
	ssize_t	read_ret;

	raw_line	= NULL;
	if (!(buf1 = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	*buf1		= '\0';
	while (!ft_strchr(buf1, '\n'))
	{
		if ((read_ret = read(fd, buf1, BUFFER_SIZE)) <= 0)
			break ;
		buf1[read_ret] = '\0';
		buf2 = ft_strcjoin(raw_line, buf1, '\0');
		free(raw_line);
		raw_line = ft_strcdup(buf2, '\0');
		free(buf2);
	}
	free(buf1);
	return (raw_line);
}

static char	*gnl_split(char *buf, char *save)
{
	char	*line;
	char	*nlptr;

	if (buf == NULL && save[0] != '\0')
	{
		line = ft_strcdup(save, '\0');
		save[0] = '\0';
	}
	else if (buf == NULL && save[0] == '\0')
		return (NULL);
	else if (!(ft_strchr(buf, '\n')) && save[0] != '\0')
	{
		line = ft_strcjoin(save, buf, '\0');
		save[0] = '\0';
	}
	else if (!(ft_strchr(buf, '\n')) && save[0] == '\0')
		line = ft_strcdup(buf, '\0');
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
	static char	save[BUFFER_SIZE + 1];
	char		*raw_line;
	char		*line;

	if ((line = check_save(save)) != NULL)
		return (line);
	raw_line = ft_read_buffer(fd);
	line = gnl_split(raw_line, save);
	free(buf);
	return (line);
}
#endif
