/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/12 03:04:05 by anvieira         ###   ########.fr       */
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
	cub3d->north_img = mlx
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
	init_textures(&cub3d);
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
	render_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS);
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
