/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:57:29 by sguerra-          #+#    #+#             */
/*   Updated: 2021/06/23 13:01:05 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		x++;
	}
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		count;
	size_t		start2;

	start2 = start;
	count = 0;
	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	ptr = malloc((sizeof(char) * (len) + 1));
	if (!ptr)
		return (0);
	while (start < (len + start2))
		ptr[count++] = s[start++];
	ptr[count] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (s[0] == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		c;
	int		it;

	it = 0;
	c = ft_strlen(s);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	while (it < c)
	{
		str[it] = s[it];
		it++;
	}
	str[c] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		dst[x] = s2[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (dst);
}
