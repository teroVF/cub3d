/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/10 20:43:29 by wcorrea-         ###   ########.fr       */
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
	init_player(&cub3d->player);
}

void	get_screen_size(t_game *cub3d, void	*tmp_mlx, void	*tmp_win)
{
	tmp_mlx = mlx_init();
	tmp_win = mlx_new_window(tmp_mlx, 1, 1, "tmp");
	mlx_get_screen_size(tmp_mlx, &cub3d->game_w, &cub3d->game_h);
	mlx_destroy_window(tmp_mlx, tmp_win);
	mlx_destroy_display(tmp_mlx);
	free(tmp_mlx);
}

void	launch_game(char *file)
{
	t_game	cub3d;

	ft_memset(&cub3d, 0, sizeof(t_game));
	init_game(&cub3d);
	parse_file(&cub3d, file);
	get_screen_size(&cub3d, NULL, NULL);
	render_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS);
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
