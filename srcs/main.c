/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:00:11 by gneve             #+#    #+#             */
/*   Updated: 2021/04/30 15:45:47 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cube.h"
#include <unistd.h>

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_cubein	cubin;

	cubin = (t_cubein){NULL, 0, 0};

	printf("ARGC %d\n", argc);
	if (argc == 2)
	{
		map_read(&cubin, argv[1]);
	}

	t_col col;

	col.sep.a = 0xF4;
	col.sep.r = 0xFB;
	col.sep.g = 0xFC;
	col.sep.b = 0xFD;

	printf("color %X\n", col.color);

}
