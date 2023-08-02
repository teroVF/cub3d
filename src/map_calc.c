/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:38:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/03 00:23:07 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"

typedef struct s_player
{
	int pos_x;
	int pos_y;
}               t_player;

void    map_calc(t_player *player)
{
    player->map_square = floor(player->pos_x);
    player->map_square = floor(player->pos_y);
}



double  dist_to_wall_x(t_player *p, int *step_x)
{
    double dist_to_side_x;
    
    if (p->ray_dir.x < 0)
	{
        dist_to_side_x = (p->pos_x - p->map_square_x) * p->delta_dist_x;
		*step_x += -1;
	}
    else
	{
        dist_to_side_x = (p->map_square_x + 1 - p->pos_x) * p->delta_dist_x;
		*step_x += 1;
	}
    return (dist_to_side_x);
}

double dist_to_wall_y(t_player *p, int *step_y)
{
    double dist_to_side_y;
    
    if (p->ray_dir.y < 0)
	{
        dist_to_side_y = (p->pos_y - p->map_square_y) * p->delta_dist_y;
		*step_y += -1;
	}
    else
	{
        dist_to_side_y = (p->map_square_y + 1 - p->pos_y) * p->delta_dist_y;
		*step_y += 1;
	}
    return (dist_to_side_y);
}

double dd_algth(void)
{
    double  dist_to_wall_x;
    double  dist_to_wall_y;
    int     *step_x;
    int     *step_y;
	char map[10][10] = 
    {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', 'p', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '1', '0', '1'},
        {'1', '0', '0', '0', '1', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };
	int map[] = {1, 0};

	*step_x = 0;
	*step_y = 0;
	dist_to_wall_x = dist_to_wall_x(p, step_x);
	dist_to_wall_y = dist_to_wall_y(p, step_y);
	while (p->map_hit[p->map_square_x][p->map_square_y] > 0)
	{
		if (dist_to_wall_x < dist_to_wall_y)
		{
			dist_to_wall_x += dist_to_wall_x(p, step_x);
			map[0] += *step_x;
			hit_side = 0;
		}
		else
		{
			dist_to_wall_y += dist_to_wall_y(p, step_y);
			map[1] += *step_y;
			hit_side = 1;
		}
	}
	printf("hit_side: %d\n", hit_side);
	return	(0)
}

int main ()
{
	dd_algth();
	return (0);
}
