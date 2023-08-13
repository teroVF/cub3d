/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/13 03:40:22 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_player(t_player *player)
{
	player->dir.x = ZERO;
	player->dir.y = -ONE;
	player->plane.x = PLANE;
	player->plane.y = ZERO;
}

void init_textures(t_game *cub3d)
{
	int	size;
	
	size = TEXTURE_SIZE;
	cub3d->north_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->north, \
		&size, &size);
	printf("north: %s\n", cub3d->north);
	cub3d->north_img.addr = mlx_get_data_addr(cub3d->north_img.img, \
		&cub3d->north_img.bpp, &cub3d->north_img.line_len, \
		&cub3d->north_img.endian);
	cub3d->south_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->south, \
		&size, &size);
	cub3d->south_img.addr = mlx_get_data_addr(cub3d->south_img.img, \
		&cub3d->south_img.bpp, &cub3d->south_img.line_len, \
		&cub3d->south_img.endian);

	cub3d->east_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->east, \
		&size, &size);
	cub3d->east_img.addr = mlx_get_data_addr(&cub3d->east_img.img, \
		&cub3d->east_img.bpp, &cub3d->east_img.line_len, \
		&cub3d->east_img.endian);
	cub3d->west_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->west, \
		&size, &size);
	cub3d->west_img.addr = mlx_get_data_addr(cub3d->west_img.img, \
		&cub3d->west_img.bpp, &cub3d->west_img.line_len, \
		&cub3d->west_img.endian);

}

void	init_game(t_game *cub3d)
{
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->east = NULL;
	cub3d->west = NULL;
	cub3d->line = NULL;
	cub3d->colors = NULL;
	cub3d->ceiling = -1;
	cub3d->floor = -1;
	cub3d->spawn = 0;
	cub3d->start_map = NO;
	cub3d->temp_map = NULL;
	cub3d->empty_line = NO;
	cub3d->game_h = WIN_H;
	cub3d->game_w = WIN_W;
	init_player(&cub3d->player);
}

void	get_screen_size(t_game *cub3d, void	*tmp_mlx, void	*tmp_win, int split)
{
	tmp_mlx = mlx_init();
	tmp_win = mlx_new_window(tmp_mlx, 1, 1, "tmp");
	mlx_get_screen_size(tmp_mlx, &cub3d->game_w, &cub3d->game_h);
	mlx_destroy_window(tmp_mlx, tmp_win);
	mlx_destroy_display(tmp_mlx);
	free(tmp_mlx);
	if (split == 2 || split == 3 || split == 4)
	{
		cub3d->game_w /= split;
		cub3d->game_h /= split;
	}
}

void	launch_game(char *file)
{
	t_game	cub3d;

	ft_memset(&cub3d, 0, sizeof(t_game));
	init_game(&cub3d);
	parse_file(&cub3d, file);
	get_screen_size(&cub3d, NULL, NULL, 0);
	printf("game_w: %d\n", cub3d.game_w);
	render_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS);
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
