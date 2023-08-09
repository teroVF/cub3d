/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:19:05 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/09 21:24:55 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_position_square(t_player *player)
{
	player->map_square.x = floor(player->pos.x);
	player->map_square.y = floor(player->pos.y);
}

void	calculate_delta(t_game *g)
{
	g->player.delta_dist_x = fabs(1 / g->player.ray_dir.x);
	g->player.delta_dist_y = fabs(1 / g->player.ray_dir.y);

	if(g->player.ray_dir.x < 0)
	{
		g->player.dist_to_side_x = (g->player.pos.x - g->player.map_square.x) * g->player.delta_dist_x;
		g->player.step_x = -1;
	}
	else
	{
		g->player.dist_to_side_x = (g->player.map_square.x + 1.0 - g->player.pos.x) * g->player.delta_dist_x;
		g->player.step_x = 1;
	}
	if(g->player.ray_dir.y < 0)
	{
		g->player.dist_to_side_y = (g->player.pos.y - g->player.map_square.y) * g->player.delta_dist_y;
		g->player.step_y = -1;
	}
	else
	{
		g->player.dist_to_side_y = (g->player.map_square.y + 1.0 - g->player.pos.y) * g->player.delta_dist_y;
		g->player.step_y = 1;
	}
}

void	dda(t_game *g)
{
	int	hit = 0;
	//     printf(" print map\n");
	// printf("0 1 2 3 4 5 6 7 8 9 \n");
	// printf("%c %c %c %c %c %c %c %c %c %c 0\n", map[0][0], map[0][1], map[0][2], map[0][3], map[0][4], map[0][5], map[0][6], map[0][7], map[0][8], map[0][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 1\n", map[1][0], map[1][1], map[1][2], map[1][3], map[1][4], map[1][5], map[1][6], map[1][7], map[1][8], map[1][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 2\n", map[2][0], map[2][1], map[2][2], map[2][3], map[2][4], map[2][5], map[2][6], map[2][7], map[2][8], map[2][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 3\n", map[3][0], map[3][1], map[3][2], map[3][3], map[3][4], map[3][5], map[3][6], map[3][7], map[3][8], map[3][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 4\n", map[4][0], map[4][1], map[4][2], map[4][3], map[4][4], map[4][5], map[4][6], map[4][7], map[4][8], map[4][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 5\n", map[5][0], map[5][1], map[5][2], map[5][3], map[5][4], map[5][5], map[5][6], map[5][7], map[5][8], map[5][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 6\n", map[6][0], map[6][1], map[6][2], map[6][3], map[6][4], map[6][5], map[6][6], map[6][7], map[6][8], map[6][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 7\n", map[7][0], map[7][1], map[7][2], map[7][3], map[7][4], map[7][5], map[7][6], map[7][7], map[7][8], map[7][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 8\n", map[8][0], map[8][1], map[8][2], map[8][3], map[8][4], map[8][5], map[8][6], map[8][7], map[8][8], map[8][9]);
	// printf("%c %c %c %c %c %c %c %c %c %c 9\n", map[9][0], map[9][1], map[9][2], map[9][3], map[9][4], map[9][5], map[9][6], map[9][7], map[9][8], map[9][9]);

	// printf("Posicao do player: %f %f\n", g->player.pos.x, g->player.pos.y);
	while (hit == 0)
	{
		// printf("////comparacao\n");
		// printf("dist_to_side_x: %f\n", g->player.dist_to_side_x);
		// printf("dist_to_side_y: %f\n", g->player.dist_to_side_y);
		if (g->player.dist_to_side_x < g->player.dist_to_side_y)
		{
			g->player.dist_to_side_x += g->player.delta_dist_x;
			g->player.map_square.x += g->player.step_x;
			g->player.hit_side = 0;
			// printf("step_x: %d\n", g->player.step_x);
			// printf("map_square.x: %d\n", g->player.map_square.x);
			// printf("map_square.y: %d\n", g->player.map_square.y);
			// printf("bateu em que lado: %d\n", g->player.hit_side);
			// printf("map: %c\n", map[g->player.map_square.y][g->player.map_square.x]);
		}
		else
		{
			g->player.dist_to_side_y += g->player.delta_dist_y;
			g->player.map_square.y += g->player.step_y;
			g->player.hit_side = 1;
			// printf("step_y: %d\n", g->player.step_y);
			// printf("map_square.x: %d\n", g->player.map_square.x);
			// printf("map_square.y: %d\n", g->player.map_square.y);
			// printf("bateu em que lado: %d\n", g->player.hit_side);
			// printf("map: %c\n", map[g->player.map_square.y][g->player.map_square.x]);
			
		}
		if (g->map[g->player.map_square.y][g->player.map_square.x] == '1')
			hit = 1;
	}
	// printf("hit_side: %d\n", g->player.hit_side);
	// printf("map_square.x: %d\n", g->player.map_square.x);
	// printf("map_square.y: %d\n", g->player.map_square.y);
	// printf("map: %c\n", map[g->player.map_square.y][g->player.map_square.x]);
}

void	calculate_distance(t_game *g)
{
	t_player	*p;

	p = &g->player;
	if (p->hit_side == 0)
		p->size_ray = perpendicular_dist_x(p, p->step_x);
	else
		p->size_ray = perpendicular_dist_y(p, p->step_y);
	// printf("size_ray: %f\n", p->size_ray);
}

void	calculate_height_wall(t_game *game)
{
	t_player	*p;

	p = &game->player;
	p->tall_of_wall = ((double)game->game_h / p->size_ray);
	p->tall_of_wall_y1 = (game->game_h / 2.00) + (p->tall_of_wall / 2.00);
	p->tall_of_wall_y2 = (game->game_h / 2.00) - (p->tall_of_wall / 2.00);
}
