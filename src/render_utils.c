/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:22:44 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/10 17:38:05 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_position_square(t_player *player)
{
	player->map_square.x = floor(player->pos.x);
	player->map_square.y = floor(player->pos.y);
}

void	my_mlx_pixel_put(t_game *cub3d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	if (x > cub3d->game_w || y > cub3d->game_h)
		return ;
	dst = cub3d->frame.addr + (y * cub3d->frame.line_length + x \
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
