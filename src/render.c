/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:22:44 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 03:54:10 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int create_floor(t_game *g)
{
    int x;
    int y;
    y = g->game_h / 2;
    x = 0;

    while (y < g->game_h)
    {
        x = 0;
        while (x < g->game_w)
        {
            mlx_pixel_put(g->mlx, g->window, x, y, g->color_floor);
            x++;
        }
        y++;
    }

    return (0);
}

static int create_ceiling(t_game *g)
{
    int x;
    int y;
    y = 0;
    x = 0;

    while (y < g->game_h / 2)
    {
        x = 0;
        while (x < g->game_w)
        {
            mlx_pixel_put(g->mlx, g->window, x, y, g->color_ceiling);
            x++;
        }
        y++;
    }

    return (0);
}

int create_background(t_game *g)
{
    create_floor(g);
    create_ceiling(g); 
    mlx_loop(g->mlx);
    return (0);
}