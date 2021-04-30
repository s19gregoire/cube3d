/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 05:28:16 by gneve             #+#    #+#             */
/*   Updated: 2021/04/30 15:46:02 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

# define NUM_KEYS 8

# define NUM_TEX 5

typedef struct s_int_vector
{
	int		x;
	int		y;
}	t_ivec;

typedef struct s_cubein {
	char	*texpaths[NUM_TEX];
	t_ivec	resol;
	t_ivec	map_siz;
}	t_cubein;

typedef union u_colors {
	struct s_colors_separate
	{
		u_int8_t	a;
		u_int8_t	r;
		u_int8_t	g;
		u_int8_t	b;
	} sep;
	u_int32_t		color;
}	t_col;

int	map_read(t_cubein *m, char *p);
#endif