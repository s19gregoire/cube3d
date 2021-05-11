/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:55:59 by gneve             #+#    #+#             */
/*   Updated: 2021/05/11 12:08:17 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <fcntl.h>
#include <stdio.h>

#if 1
void	get_data(int key, t_cubein *g, char *line)
{
	static	int (*getters[NUM_KEYS])(int, t_cubein *, char *line) = {
		get_resolution,
		get_tex, get_tex, get_tex, get_tex, get_tex,
		get_color, get_color
	};

	if (key >= 0 && key < NUM_KEYS)
	{
		return (getters[key](key, g, line));
	}
	return (1);
}
#endif

int	read_line(char *line, t_cubein *g)
{
	int			i;
	static char	*keys[NUM_KEYS] = {
		"R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "};

	i = 0;
	while (i < NUM_KEYS && line && ft_strncmp(line, keys[i], 3) == 0)
	{
		return (i);
	}
	return (-1);
}

int	map_read(t_cubein *m, char *p)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	fd = open(p, O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		read_line(line, m);
		free(line);
	}
	return (0);
}
