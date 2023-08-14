/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:50:24 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/15 00:51:49 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int wall_collision(t_game *game, double x, double y)
{
	printf("x: %f y: %f\n", x, y);
	printf("x: %d y: %d\n", (int)x, (int)y);
	printf("map: %c\n", game->map[(int)y][(int)x]);
	if (game->map[(int)y + 1][(int)x] == '1' && game->map[(int)y][(int)x + 1] == '1' && game->player.dir.x > 0 && game->player.dir.y > 0)
	{
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x, (int)y +1);
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x + 1, (int)y);
		return (1);
	}
	if (game->map[(int)y][(int)x - 1] == '1' && game->map[(int)y + 1][(int)x] == '1' && game->player.dir.x < 0 && game->player.dir.y > 0)
	{
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x - 1, (int)y);
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x, (int)y + 1);
		return (1);
	}
	if (game->map[(int)y - 1][(int)x] == '1' && game->map[(int)y][(int)x +1] == '1' && game->player.dir.x > 0 && game->player.dir.y < 0)
	{
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x, (int)y - 1);
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x + 1, (int)y);
		return (1);
	}
	if (game->map[(int)y][(int)x - 1] == '1' && game->map[(int)y - 1][(int)x] == '1' && game->player.dir.x < 0 && game->player.dir.y < 0)
	{
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x - 1, (int)y);
		printf("eh o 1 nos quadrados de coordenadas x: %d y: %d\n", (int)x, (int)y - 1);
		return (1);
	}
	return (0);
}
void	move_positionx(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;
	t_vector	temp;

	temp.x = dir->x;
	temp.y = dir->y;
	rotate_vector(&temp, PI / 2);
	p = &game->player;
	p->pos.y += MOV * temp.y * direction;
	p->pos.x += MOV * temp.x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] != '0')
	{
		p->pos.y -= MOV * temp.y * direction;
		p->pos.x -= MOV * temp.x * direction;
		return ;
	}
	else if (wall_collision(game, p->pos.x, p->pos.y))
	{
		p->pos.y -= MOV * temp.y * direction;
		p->pos.x -= MOV * temp.x * direction;
		return ;
	}
	rayscasting(game);
}
void	move_positiony(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;

	p = &game->player;
	p->pos.y += MOV * dir->y * direction;
	p->pos.x += MOV * dir->x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] != '0')
	{
		p->pos.y -= MOV * dir->y * direction;
		p->pos.x -= MOV * dir->x * direction;
		return ;
	}
	else if (wall_collision(game, p->pos.x, p->pos.y))
	{
		p->pos.y -= MOV * dir->y * direction;
		p->pos.x -= MOV * dir->x * direction;
		return ;
	}
	rayscasting(game);
}



void	rotate_left(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;

	p = &game->player;
	olddirx = p->dir.x;
	p->dir.x = p->dir.x * cos(ROT) - p->dir.y * sin(-ROT);
	p->dir.y = olddirx * sin(-ROT) + p->dir.y * cos(-ROT);
	oldplanex = p->plane.x;
	p->plane.x = p->plane.x * cos(-ROT) - p->plane.y * sin(-ROT);
	p->plane.y = oldplanex * sin(-ROT) + p->plane.y * cos(-ROT);
	rayscasting(game);
}

void	rotate_right(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;

	p = &game->player;
	olddirx = p->dir.x;
	p->dir.x = p->dir.x * cos(ROT) - p->dir.y * sin(ROT);
	p->dir.y = olddirx * sin(ROT) + p->dir.y * cos(ROT);
	oldplanex = p->plane.x;
	p->plane.x = p->plane.x * cos(ROT) - p->plane.y * sin(ROT);
	p->plane.y = oldplanex * sin(ROT) + p->plane.y * cos(ROT);
	rayscasting(game);
}

int	read_keys(int keypress, t_game *game)
{	
	printf("Antes: \n");
	printf("posicao x: %f\n", game->player.pos.x);
	printf("posicao y: %f\n", game->player.pos.y);
	printf("map: %c\n", game->map[(int)game->player.pos.y][(int)game->player.pos.x]);
	if (keypress == KEY_ESC)
		end_game(game);
	if (keypress == W)
		move_positiony(game, &game->player.dir, 1);
	if (keypress == S)
		move_positiony(game, &game->player.dir, -1);
	if (keypress == A)
		move_positionx(game, &game->player.dir, -1);
	if (keypress == D)
		move_positionx(game, &game->player.dir, 1);
	if (keypress == LEFT)
		rotate_left(game);
	if (keypress == RIGHT)
		rotate_right(game);
	printf("Depois: \n");
	printf("posicao x: %f\n", game->player.pos.x);
	printf("posicao y: %f\n", game->player.pos.y);
	printf("map: %c\n", game->map[(int)game->player.pos.y][(int)game->player.pos.x]);
	return (0);
}
