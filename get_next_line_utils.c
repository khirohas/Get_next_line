/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 08:44:07 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/25 08:44:07 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef BUFFER_SIZE
char	*read_buffer(int fd)
{
	size_t	buffer_count = 1;
	char	*buf1 = NULL;
	char	*buf2 = NULL;
	char	*nl;

	buf1 = malloc(BUFFER_SIZE * buffer_count + 1);
	if(!read(fd, buf1, BUFFER_SIZE * buffer_count))
		return (NULL);
	buf1[BUFFER_SIZE] = '\0';
	nl = ft_strchr(buf1, '\n');
	buffer_count++;

while (!nl)
{
	if (buffer_count % 2 == 0)
	{
		buf2 = malloc(BUFFER_SIZE * buffer_count + 1);
		ft_memmove(buf2, buf1, BUFFER_SIZE * (buffer_count - 1));
		free(buf1);
		read(fd, buf2 + (BUFFER_SIZE * (buffer_count - 1)), BUFFER_SIZE);
		buf2[BUFFER_SIZE * buffer_count] = '\0';
		buffer_count++;
		nl = ft_strchr(buf2, '\n');
	}
	else
	{
		buf1 = malloc(BUFFER_SIZE * buffer_count + 1);
		ft_memmove(buf1, buf2, BUFFER_SIZE * (buffer_count - 1));
		free(buf2);
		read(fd, buf1 + (BUFFER_SIZE * (buffer_count - 1)), BUFFER_SIZE);
		buf1[BUFFER_SIZE * buffer_count] = '\0';
		buffer_count++;
		nl = ft_strchr(buf1, '\n');
	}
	}
	if (buffer_count % 2 == 0)
			return (buf1);
	else
		return (buf2);
}


size_t	ft_strlen(char const *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

#endif
