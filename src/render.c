/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:22:44 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/09 02:34:29 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static inline int create_floor(t_game *g)
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
            mlx_pixel_put(g->mlx, g->window, x, y, g->floor);
            x++;
        }
        y++;
    }

    return (0);
}

static inline int create_ceiling(t_game *g)
{
    int x;
    int y;
    y = 0;
    x = 0;

    while (y < g->game_h)
    {
        x = 0;
        while (x < g->game_w)
        {
            mlx_pixel_put(g->mlx, g->window, x, y, g->ceiling);
            x++;
        }
        y++;
    }

    return (0);
}

inline int create_background(t_game *g)
{
    create_ceiling(g); 
    create_floor(g);
    return (0);
}