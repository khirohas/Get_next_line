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
#include <stdio.h>
#ifdef BUFFER_SIZE

static char	*check_save(char *save)
{
	char	*line;
	if (!save || !(line = ft_strcdup(save, '\n')))
		return (NULL);
	return (line);
}

static char	*ft_read_buffer(int fd)
{
	char	buf1[BUFFER_SIZE + 1];
	char	*buf2;
	char	*raw_line;
	ssize_t	read_ret;

	raw_line	= NULL;
	*buf1		= '\0';
	read_ret	= BUFFER_SIZE;

	while (!ft_strchr(buf1, '\n')) /*&& (read_ret = read(fd, buf1, BUFFER_SIZE)) > 0)
*/
	{	
		if ((read_ret = read(fd, buf1, BUFFER_SIZE)) <= 0)
			break ;
		buf1[read_ret] = '\0';
		buf2 = ft_strcjoin(raw_line, buf1, '\0');
		free(raw_line);
		raw_line = ft_strcdup(buf2, '\0');
		free(buf2);
	}
	return (raw_line);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*buf;
	char		*line;
	char		*nlptr;

	if ((line = check_save(save)) != NULL)
	{
		nlptr = (ft_strchr(save, '\n') + 1);
		ft_strlcpy(save, nlptr, ft_strlen(nlptr) + 1);
		return (line);
	}
	if ((buf = ft_read_buffer(fd)) == NULL)
		{
			if (save[0] != '\0')
			{
				line = ft_strcdup(save, '\0');
				save[0] = '\0';
				return (line);
			}
			else
				return (NULL);
		}
	else if (!(ft_strchr(buf, '\n')))
	{
		if (save[0] != '\0')
		{
			line = ft_strcjoin(save, buf, '\0');
			save[0] = '\0';
		}
		else
			line = ft_strcdup(buf, '\0');
	}
	else
	{
		line = ft_strcjoin(save, buf, '\n');
		nlptr = (ft_strchr(buf, '\n') + 1); 
		ft_strlcpy(save, nlptr, ft_strlen(nlptr) + 1);
	}
	free(buf);
	return (line);
}
#endif
