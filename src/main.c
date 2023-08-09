/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/09 18:59:52 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	convert_int_bit_to_rgb(t_game *cub3d, int r, int g, int b)
{
	r = (cub3d->floor >> 16) & 0xFF;
	g = (cub3d->floor >> 8) & 0xFF;
	b = cub3d->floor & 0xFF;
	printf("floor  : %d,%d,%d\n", r, g, b);
	r = (cub3d->ceiling >> 16) & 0xFF;
	g = (cub3d->ceiling >> 8) & 0xFF;
	b = cub3d->ceiling & 0xFF;
	printf("ceiling: %d,%d,%d\n", r, g, b);
}

void init_player(t_player *player)
{
    player->dir.x = STD_X;
    player->dir.y = STD_Y;
    player->plane.x = STD_PLANE_X;
    player->plane.y = STD_PLANE_Y;
    // player->move_speed = 0.05;
    // player->rot_speed = 0.05;
}

void	init_game(t_game *cub3d)
{
	// ft_bzero(cub3d, sizeof(t_game));
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

void	launch_game(char *file)
{
	t_game	cub3d;
	ft_memset(&cub3d, 0, sizeof(t_game));
	init_game(&cub3d);
	parse_file(&cub3d, file);
    render_game(&cub3d);
	quit_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS);
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
