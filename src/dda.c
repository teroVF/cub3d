/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:31:50 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 03:46:17 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void map_position_square(t_player *player)
{
    player->map_square_x = floor(player->pos_x);
    player->map_square_y = floor(player->pos_y);
}

void dda(t_game *game)
{
    t_player *p;
    p = &game->player;
    map_position_square(p);
    if (p.ray_dir.x == 0)
    {
        p.dist_to_wallx = 1;
        p.dist_to_wally = 0;
    }
    else if (p.ray_dir.y == 0)
    {
        p.dist_to_wallx = 0;
        p.dist_to_wally = 1;
    }
    else
    {
        p.dist_to_wallx = dist_to_wall_x(p);
        p.dist_to_wally = dist_to_wall_y(p);
    }
    while (map[p.map_square_y][p.map_square_x] != '1')
    {
        ////////////////////////
        if (p.ray_dir.x == 0)
        {
            p.dist_to_wallx = 1;
            p.dist_to_wally = 0;
        }
        else if (p.ray_dir.y == 0)
        {
            p.dist_to_wallx = 0;
            p.dist_to_wally = 1;
        }
        ////////////////////////
        if (p.dist_to_wallx < p.dist_to_wally)
        {
            p.dist_to_wallx += dist_to_wall_x(&p);
            p.map_square_x += p.step_x;
            p.hit_side = 0;
        }
        else
        {
            dist_to_wally += dist_to_wall_y(&p);
            p.map_square_y += p.step_y;
            p.hit_side = 1;
        }
    }
    printf("map_square_x: %d\n", p.map_square_x);
    printf("map_square_y: %d\n", p.map_square_y);
    printf("hit_side: %d\n", p.hit_side);
    if (p.hit_side == 0)
        p.size_ray = perpendicular_dist_x(p, p.step_x);
    else
        p.size_ray = perpendicular_dist_y(p, p.step_y);
    printf("size_ray: %f\n", p.size_ray);
    p.tall_of_wall = (game->game_h / p.size_ray);
    p.tall_of_wall_y1 = (game->game_h / 2) - (p.tall_of_wall / 2);
    p.tall_of_wall_y2 = (game->game_h / 2) + (p.tall_of_wall / 2);
}