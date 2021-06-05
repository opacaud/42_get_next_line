/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:40:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/05/21 12:06:19 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char			*ft_before(char *str);
char			*ft_after(char *str);
int				get_next_line(int fd, char **line);
unsigned int	ft_strlen(char *s);
int				ft_hasnewline(char *s);
char			*ft_strjoin(char *s1, char *s2);

#endif
