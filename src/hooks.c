/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:24 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/06 06:48:36 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int end_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    exit(EXIT_SUCCESS);
}

void move_positionx (t_game *game, int direction)
{
    t_player *p;
    double speed;
    speed = 0.2;
    p = &game->player;
    p->pos.x += speed * direction;
    rayscasting(game);
    // printf("////////////////////////////////////\n");
    
    // printf("y: %f\n", p->pos.y);
    // printf("x: %f\n", p->pos.x);
}

void move_positiony (t_game *game, int direction)
{
    t_player *p;
    double speed;
    speed = 0.2;
    p = &game->player;
    p->pos.y += speed * direction;
    rayscasting(game);
    // printf("////////////////////////////////////\n");
    
    // printf("y: %f\n", p->pos.y);
    // printf("x: %f\n", p->pos.x);
}

void rotate_left(t_game *game)
{
    t_player *p;
    double olddirx;
    double oldplanex;
    double rot_speed;
    rot_speed = 0.1;
    
    p = &game->player;
    olddirx = p->dir.x;
    p->dir.x = p->dir.x * cos(rot_speed) - p->dir.y * sin(-rot_speed);
    p->dir.y = olddirx * sin(-rot_speed) + p->dir.y * cos(-rot_speed);
    oldplanex = p->plane.x;
    p->plane.x = p->plane.x * cos(-rot_speed) - p->plane.y * sin(-rot_speed);
    p->plane.y = oldplanex * sin(-rot_speed) + p->plane.y * cos(-rot_speed);
    rayscasting(game);
}
void rotate_right(t_game *game)
{
    t_player *p;
    double olddirx;
    double oldplanex;
    double rot_speed;
    rot_speed = 0.1;
    
    p = &game->player;
    olddirx = p->dir.x;
    p->dir.x = p->dir.x * cos(rot_speed) - p->dir.y * sin(rot_speed);
    p->dir.y = olddirx * sin(rot_speed) + p->dir.y * cos(rot_speed);
    oldplanex = p->plane.x;
    p->plane.x = p->plane.x * cos(rot_speed) - p->plane.y * sin(rot_speed);
    p->plane.y = oldplanex * sin(rot_speed) + p->plane.y * cos(rot_speed);
    rayscasting(game);
}


int	read_keys(int keypress, t_game *game)
{
	if (keypress == KEY_ESC)
        end_game(game);
    if (keypress == A)
        move_positionx(game, -1);
    if (keypress == D)
        move_positionx(game, 1);
    if (keypress == W)
        move_positiony(game, -1);
    if (keypress == S)
        move_positiony(game, 1);
    if(keypress == LEFT)
        rotate_left(game);
    if(keypress == RIGHT)
        rotate_right(game);
    
    
    return (0);
}