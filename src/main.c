/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 04:39:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 15:47:59 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"

char map[10][10] =
	{	//0    1    2    3    4    5    6    7    8    9
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, //0
		{'1', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, //1
		{'1', '0', '0', '1', '1', '1', '1', '0', '1', '1'}, //2
		{'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //3
		{'1', '0', '1', '0', '0', '0', '0', '0', '1', '1'}, //4
		{'1', '0', '1', '1', '0', '0', '0', '0', '1', '1'}, //5
		{'1', '0', '1', '1', '0', '0', '1', '0', '1', '1'}, //6
		{'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //7
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '1'}, //8
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}  //9
	};

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
    while (y < g->player.tall_of_wall_y2)
    {
        mlx_pixel_put(g->mlx, g->window, x, y, color);
        y++;
    }
}

//Multiplicador = 2 * (x/width) -1
int rayscasting(t_game  *g)
{
    g->pixel = 0;
    g->color_floor = 0x5ED41D;
    g->color_ceiling = 0x5ED4E1;
    create_background(g);
    g->player.pos.x = 5;
    g->player.pos.y = 5;
    g->player.dir.y = 0;
    g->player.dir.x = -1;
    g->player.plane.x = 0.66;
    g->player.plane.y = 0;
    while (g->pixel < g->game_w)
    {
        g->player.ray_dir.x = g->player.dir.x + g->player.plane.x * (2 * (g->pixel / g->game_w) - 1);
        g->player.ray_dir.y = g->player.dir.y + g->player.plane.y * (2 * (g->pixel / g->game_w) - 1);
        dda(g);
        render_collumn_pixel(g);
        g->pixel++;
    }

    return (0);
}


int main(void)
{
    t_game g;
    g.game_w = 320;
    g.game_h = 200;
    g.mlx = mlx_init();
    g.window = mlx_new_window(g.mlx, g.game_w, g.game_h, "Cub3D");
    rayscasting(&g);
    return (0);
}