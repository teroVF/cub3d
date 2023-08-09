/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/09 01:06:35 by anvieira         ###   ########.fr       */
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
    player->pos.x = 2;
    player->pos.y = 2;
    player->dir.x = 0;
    player->dir.y = -1;
    player->plane.x = 0;
    player->plane.y = 0.66;
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
