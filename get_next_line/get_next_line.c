/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:36:53 by apons             #+#    #+#             */
/*   Updated: 2019/01/11 13:50:21 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_joindel(char *s1, const char *s2)
{
	char	*s3;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s1 && s2))
		return (NULL);
	if (!(s3 = ft_strnew(len)))
		return (NULL);
	s3 = ft_strcat(s3, s1);
	s3 = ft_strcat(s3, s2);
	s3[len] = '\0';
	free(s1);
	return (s3);
}

char		*ft_strndup(char *s1, char *s2, size_t n)
{
	if (!(s2 = ft_strnew(n)))
		return (0);
	s2 = ft_strncat(s2, s1, n);
	s2[n] = '\0';
	return (s2);
}

void		ft_restock(char **keep, size_t i)
{
	char	*tmp;

	tmp = *keep;
	*keep = ft_strdup(*keep + i + 1);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	size_t		size;
	char		buffer[BUFF_SIZE + 1];
	static char *keeper = NULL;

	if (!line || !BUFF_SIZE || read(fd, buffer, 0) < 0)
		return (-1);
	(!keeper) ? keeper = ft_strnew(0) : 0;
	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[size] = '\0';
		if (!(keeper = ft_joindel(keeper, buffer)))
			return (-1);
		if (ft_strchr(keeper, '\n'))
			break ;
	}
	if ((size < BUFF_SIZE) && (ft_strlen(keeper) == 0))
		return (0);
	size = 0;
	while (keeper[size] != '\n' && keeper[size])
		size++;
	*line = ft_strndup(keeper, *line, size);
	(size < ft_strlen(keeper)) ? ft_restock(&keeper, size) : ft_strdel(&keeper);
	return (1);
}
