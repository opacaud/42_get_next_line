/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:51 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/21 12:01:39 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_hasnewline(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (s1 == 0 && s2 == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == 0)
		return (0);
	i = -1;
	size = ft_strlen(s1);
	while (++i < size)
		res[i] = s1[i];
	j = -1;
	size = ft_strlen(s2);
	while (++j < size)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free (s1);
	return (res);
}
