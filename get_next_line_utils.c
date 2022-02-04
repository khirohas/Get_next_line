/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 08:44:07 by khirohas          #+#    #+#             */
/*   Updated: 2022/02/04 23:45:35 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef BUFFER_SIZE

size_t	ft_strlen(char const *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
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

char	*ft_strcdup(const char *str, char c)
{
	char	*dst;
	size_t	dstlen;

	dstlen = 0;
	while (str[dstlen] != c)
	{
		if (str[dstlen] == '\0' && c != '\0')
			return (NULL);
		dstlen++;
	}
	dstlen++;
	dst = malloc(sizeof(char) * dstlen + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, str, dstlen + 1);
	return (dst);
}

char	*ft_strcjoin(const char *s1, const char *s2, char c)
{
	char	*dst;
	size_t	dst_len;
	char	*c_ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		dst = ft_strcdup(s2, c);
	else if (s2 == NULL)
		dst = ft_strcdup(s1, c);
	else
	{
		c_ptr = ft_strchr(s2, c);
		if (c_ptr == NULL)
			return (NULL);
		dst_len = ft_strlen(s1) + (c_ptr - s2 + 1);
		dst = malloc(dst_len + 1);
		if (!dst)
			return (NULL);
		ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
		ft_strlcpy(dst + ft_strlen(s1), s2, (c_ptr - s2 + 1) + 1);
	}
	return (dst);
}
#endif
