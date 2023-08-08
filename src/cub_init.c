/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:40:11 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/08 18:25:44 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int player_init(t_player *p)
{
    p->pos.x = 5;
    p->pos.y = 5;
    p->dir.x = -1;
    p->dir.y = 0;
    p->plane.x = 0.66;
    p->plane.y = 0;

    
    return (0);
}

int game_init(t_game *g)
{
    g->game_h = WIN_H;
    g->game_w = WIN_W;
    
    return (0);
}