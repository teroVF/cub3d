/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:22:44 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/10 02:39:03 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_mlx_pixel_put(t_game *cub3d, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || y < 0)
		return ;
	if (x > cub3d->game_w || y > cub3d->game_h)
		return ;
	dst = cub3d->frame.addr + (y * cub3d->frame.line_length + x 
		* (cub3d->frame.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

inline static int	create_floor(t_game *g)
{
	int	x;
	int	y;

	y = g->game_h / 2;
	x = 0;
	while (y < g->game_h)
	{
		x = 0;
		while (x < g->game_w)
		{
			my_mlx_pixel_put(g, x, y, g->floor);
			x++;
		}
		y++;
	}
	return (0);
}

static inline int	create_ceiling(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < g->game_h)
	{
		x = 0;
		while (x < g->game_w)
		{
			my_mlx_pixel_put(g, x, y, g->ceiling);
			x++;
		}
		y++;
	}
	return (0);
}

int	create_background(t_game *g)
{
	create_ceiling(g);
	create_floor(g);
	return (0);
}
