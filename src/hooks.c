/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:24 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/10 02:43:04 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	move_positionx(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;
	double		speed;
	t_vector	temp;
	
	temp.x = dir->x;
	temp.y = dir->y;
	rotate_vector(&temp, PI / 2);
	speed = 0.2;
	p = &game->player;
	p->pos.y += speed * temp.y * direction;
	p->pos.x += speed * temp.x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] == '1')
	{
		p->pos.y -= speed * temp.y * direction;
		p->pos.x -= speed * temp.x * direction;
		return ;
	}
	rayscasting(game);
}

void	move_positiony(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;
	double		speed;
	
	speed = 0.2;
	p = &game->player;
	p->pos.y += speed * dir->y * direction;
	p->pos.x += speed * dir->x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] == '1')
	{
		p->pos.y -= speed * dir->y * direction;
		p->pos.x -= speed * dir->x * direction;
		return ;
	}
	rayscasting(game);
	printf("FIM\n");
}

void	rotate_right(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;
	double		rot_speed;

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
void	rotate_left(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;
	double		rot_speed;

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
	printf("key: %d\n", keypress);
	if (keypress == KEY_ESC)
		end_game(game);
	if (keypress == A)
		move_positionx(game, &game->player.dir, 1);
	if (keypress == D)
	{
		printf("entro\n");
		move_positionx(game, &game->player.dir, -1);
	}
	if (keypress == W)
		move_positiony(game, &game->player.dir, 1);
	if (keypress == S)
		move_positiony(game, &game->player.dir, -1);
	if (keypress == LEFT)
		rotate_left(game);
	if (keypress == RIGHT)
		rotate_right(game);
	return (0);
}
