/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:59:15 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/09 22:08:11 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate_vector(t_vector *v, double angle)
{
	double	x;
	double	y;

	x = v->x;
	y = v->y;
	v->x = x * cos(angle) - y * sin(angle);
	v->y = x * sin(angle) + y * cos(angle);
}

void	set_direction(t_game *cub3d)
{
	if (cub3d->spawn == 'S')
		rotate_vector(&cub3d->player.dir, PI);
	else if (cub3d->spawn == 'E')
	{
		rotate_vector(&cub3d->player.dir, PI / 2);
		cub3d->player.plane.x = STD_PLANE_Y;
		cub3d->player.plane.y = STD_PLANE_X;
	}
	else if (cub3d->spawn == 'W')
	{
		rotate_vector(&cub3d->player.dir, -PI / 2);
		cub3d->player.plane.x = STD_PLANE_Y;
		cub3d->player.plane.y = STD_PLANE_X;
	}
}

void	set_player_position(t_game *cub3d, int i, int j)
{
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (cub3d->map[i][j] == cub3d->spawn)
			{
				cub3d->player.pos.x = j + 0.5;
				cub3d->player.pos.y = i + 0.5;
				cub3d->map[i][j] = '0';
				set_direction(cub3d);
				return ;
			}
		}
	}
}
