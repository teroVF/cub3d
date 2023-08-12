/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 04:39:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/12 03:26:43 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	render_collumn_pixel(t_game *cub3d)
{
	int	x;
	int	y;
	int	texture;

	y = cub3d->player.tall_of_wall_y1;
	x = cub3d->pixel;
	if (cub3d->player.hit_side == 1 && cub3d->player.ray_dir.y < 0)
		texture = cub3d->north_img;
	else if (cub3d->player.hit_side == 1 && cub3d->player.ray_dir.y > 0)
		texture = cub3d->south_img;
	else if (cub3d->player.hit_side == 0 && cub3d->player.ray_dir.x < 0)
		texture = cub3d->west_img;
	else
		texture = cub3d->east_img;
	if (cub3d->player.tall_of_wall_y1 > cub3d->player.tall_of_wall_y2)
	{
		y = cub3d->player.tall_of_wall_y2;
		while (y < cub3d->player.tall_of_wall_y1 && y < cub3d->game_h)
		{
			my_mlx_pixel_put(cub3d, x, y, extract_color(textur
			y++;
		}
		return ;
	}
	while (y < cub3d->player.tall_of_wall_y2 && y < cub3d->game_h)
	{
		my_mlx_pixel_put(cub3d, x, y, color);
		y++;
	}
}

void	calculate_current_ray(t_game *cub3d)
{
	double		ray;
	t_vector	ray_pixel;

	ray = 2 * ((double)cub3d->pixel / (cub3d->game_w - 1)) - 1;
	ray_pixel = mult_vector(&cub3d->player.plane, ray);
	cub3d->player.ray_dir = add_vector(&cub3d->player.dir, &ray_pixel);
}

int	rayscasting(t_game *cub3d)
{
	if (cub3d->frame.img)
		mlx_destroy_image(cub3d->mlx, cub3d->frame.img);
	cub3d->frame.img = mlx_new_image(cub3d->mlx, cub3d->game_w, cub3d->game_h);
	cub3d->frame.addr = mlx_get_data_addr(cub3d->frame.img, \
		&cub3d->frame.bits_per_pixel, &cub3d->frame.line_length, \
		&cub3d->frame.endian);
	create_background(cub3d);
	while (cub3d->pixel < cub3d->game_w)
	{
		map_position_square(&cub3d->player);
		calculate_current_ray(cub3d);
		calculate_delta(cub3d);
		dda(cub3d);
		calculate_distance(cub3d);
		calculate_height_wall(cub3d);
		render_collumn_pixel(cub3d, 0x00FF0000, 0x00B20000);
		cub3d->pixel++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->frame.img, 0, 0);
	cub3d->pixel = 0;
	return (0);
}

int	render_game(t_game *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->window = mlx_new_window(cub3d->mlx, \
		cub3d->game_w, cub3d->game_h, "Cub3D");
	rayscasting(cub3d);
	mlx_key_hook(cub3d->window, read_keys, cub3d);
	mlx_hook(cub3d->window, 17, 1L << 0, end_game, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
