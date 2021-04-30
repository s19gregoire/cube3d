/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 06:16:53 by gneve             #+#    #+#             */
/*   Updated: 2021/04/30 13:52:42 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_bufflen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_malloc(size_t size)
{
	char	*s;
	char	*ptr;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	size = size + 1;
	ptr = s;
	while (size-- > 0)
		*ptr++ = '\0';
	return (s);
}

static char	*ft_save(char *lines, size_t *a)
{
	if (ft_strchr(lines, '\n'))
	{
		ft_strcpy(lines, ft_strchr(lines, '\n') + 1);
		return (lines);
	}
	if (ft_bufflen(lines) > 0)
	{
		ft_strcpy(lines, ft_strchr(lines, '\0'));
		*a = 0;
		return (lines);
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line_tmp;
	static char	*lines = NULL;
	int			end_buff;
	size_t		a;

	if (read(fd, buf, 0) < 0 || fd < 0 || BUFFER_SIZE < 1 || !(a = 1)
		|| line == NULL || (lines == NULL && (lines = ft_malloc(0)) == NULL))
		return (-1);
	while (ft_strchr(lines, '\n') == NULL
		&& (end_buff = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[end_buff] = '\0';
		line_tmp = lines;
		if (!(lines = ft_strjoin(line_tmp, buf)))
			return (-1);
		free(line_tmp);
	}
	if (!(*line = ft_substr(lines, 0, ft_bufflen(lines))))
		return (-1);
	if ((ft_save(lines, &a) != NULL) && a == 1)
		return (1);
	free(lines);
	lines = NULL;
	return (0);
}
