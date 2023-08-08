/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 04:39:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/08 04:13:28 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"

// char map[10][10] =
// 	{	//0    1    2    3    4    5    6    7    8    9
// 		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, //0
// 		{'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'}, //1
// 		{'1', '0', '0', '0', '0', '1', '0', '0', '0', '1'}, //2
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //3
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //4
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //5
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //6
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //7
// 		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, //8
// 		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}  //9
// 	};

void render_collumn_pixel(t_game *g)
{
    int x;
    int y;
    int color;

    y = g->player.tall_of_wall_y1;
    x = g->pixel;
    //red
    int color1 = 0x00FF0000;
    //dark red
    int color2 = 0x00B20000;
    if (g->player.hit_side == 1)
        color = color1;
    else
        color = color2;
    if (g->player.tall_of_wall_y1 > g->player.tall_of_wall_y2)
    {
        y = g->player.tall_of_wall_y2;
        while (y < g->player.tall_of_wall_y1)
        {
            mlx_pixel_put(g->mlx, g->window, x, y, color);
            y++;
        }
        return ;
    }
    
    while (y < g->player.tall_of_wall_y2)
    {
        mlx_pixel_put(g->mlx, g->window, x, y, color);
        y++;
    }
}

void calculate_current_ray(t_game *g)
{
    double ray;
    t_vector ray_pixel;
    
    ray = 2 * ((double)g->pixel / (g->game_w - 1)) - 1;
    ray_pixel = mult_vector(&g->player.plane, ray);
    g->player.ray_dir = add_vector(&g->player.dir, &ray_pixel);
}


int rayscasting(t_game  *g)
{
    create_background(g);
    while (g->pixel < g->game_w)
    {
        map_position_square(&g->player);
        calculate_current_ray(g);
        calculate_delta(g);   
        dda(g);
        calculate_distance(g);
        calculate_height_wall(g);
        render_collumn_pixel(g);
        g->pixel++;
    }
    g->pixel = 0;
    return (0);
}


int main(void)
{
    t_game g;
    ft_memset(&g, 0, sizeof(t_game));
    game_init(&g);
    g.mlx = mlx_init();
    g.window = mlx_new_window(g.mlx, g.game_w, g.game_h, "Cub3D");
    g.color_floor = 0x5ED41D;
    g.color_ceiling = 0x5ED4E1;
    g.player.pos.x = 5;
    g.player.pos.y = 5;
    g.player.dir.y = -1;
    g.player.dir.x =  0;
    g.player.plane.x = 0.66;
    g.player.plane.y = 0;
    rayscasting(&g);
    mlx_key_hook(g.window, read_keys, &g);
    mlx_hook(g.window, 17, 1L << 0, end_game, &g);
    mlx_loop(g.mlx);
    return (0);
}