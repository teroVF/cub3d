/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:47:57 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/14 15:41:55 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	obtain_color_pixel(t_data *img,
		int point_x, int point_y)
{
	return (*(int *)(img->addr + (point_y * img->line_len + point_x * \
					(img->bpp / 8))));
}

int	obtain_color(t_game *cub3d)
{
	int	x;
	int	y;

	x = cub3d->player.text_x;
	y = cub3d->player.text_y;
	if (cub3d->player.hit_side)
	{
		if (cub3d->player.pos.y > cub3d->player.map_square.y)
			return (obtain_color_pixel(&cub3d->north_img, x, y));
		else
			return (obtain_color_pixel(&cub3d->south_img, x, y));
	}
	else
	{
		if (cub3d->player.pos.x < cub3d->player.map_square.x)
			return (obtain_color_pixel(&cub3d->east_img, x, y));
		else
			return (obtain_color_pixel(&cub3d->west_img, x, y));
	}
}

void	find_out_text_x(t_player *player)
{
	double	wall;

	if (!player->hit_side)
	{
		if (player->pos.x < player->map_square.x)
			wall = player->pos.y + player->size_ray * player->ray_dir.y;
		else
			wall = player->pos.y - player->size_ray * player->ray_dir.y;
	}
	else
	{
		if (player->pos.y > player->map_square.y)
			wall = player->pos.x - player->size_ray * player->ray_dir.x;
		else
			wall = player->pos.x + player->size_ray * player->ray_dir.x;
	}
	wall -= floor(wall);
	player->text_x = (int)(wall * (double)TEXTURE_SIZE);
	printf("text_x: %d\n", player->text_x);
}
