/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:49:40 by sguerra-          #+#    #+#             */
/*   Updated: 2021/07/01 17:30:36 by sguerra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bufjoin(char **str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
}

void	ft_getline(int *ret, char **str, char **line)
{
	size_t	i;
	char	*s;

	s = ft_strdup(*str);
	free(*str);
	*str = NULL;
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	*line = ft_substr(s, 0, i);
	if (s[i] == '\n')
	{
		*str = ft_strdup(&s[i + 1]);
		*ret = 1;
	}
	else
	{
		if (*ret > 0)
			*ret = 1;
		else
			*ret = 0;
	}
	free(s);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = 0;
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
			ft_bufjoin(&str[fd], buf);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
		ret = read(fd, buf, ret);
	}
	if (ret > 0 || str[fd] != NULL)
		ft_getline(&ret, &str[fd], &*line);
	else
		if (ret > -1)
			*line = ft_strdup("");
	return (ret);
}
