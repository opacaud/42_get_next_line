/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:01:05 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/28 08:49:42 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before(char *str)
{
	unsigned int	i;
	char			*line;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_after(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free (str);
		return (0);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (res == 0)
		return (0);
	i++;
	j = 0;
	while (str[i] != '\0')
		res[j++] = str[i++];
	res[j] = '\0';
	free (str);
	return (res);
}

int	ft_error(char *buf)
{
	free (buf);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*s;

	if (line == 0 || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	ret = 1;
	while (ret > 0 && ft_hasnewline(s) == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ft_error(buf));
		buf[ret] = '\0';
		s = ft_strjoin(s, buf);
	}
	free (buf);
	*line = ft_before(s);
	s = ft_after(s);
	if (ret == 0)
		return (0);
	return (1);
}
