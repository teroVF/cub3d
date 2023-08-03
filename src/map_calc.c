/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:38:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/03 03:54:20 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"
#include <stdio.h>
#include <math.h>
typedef struct s_vector
{
	double x;
	double y;
}               t_vector;
typedef struct s_player
{
	double pos_x;
	double pos_y;
	int map_square_x;
	int map_square_y;
	t_vector ray_dir;
	int step_x;
	int step_y;
}               t_player;

double  mag_vector(t_vector *vector)
{
    return (sqrt(vector->x * vector->x + vector->y * vector->y));
}

double delta_x(t_vector *vector)
{
    return (fabs(mag_vector(vector) / vector->x));
}

//tem de ser absoluto porque o delta eh sempre positivo. vr no fim
double delta_y(t_vector *vector)
{
    return (fabs(mag_vector(vector) / vector->y));
}

void    map_calc(t_player *player)
{
    player->map_square_x = floor(player->pos_x);
    player->map_square_y = floor(player->pos_y);
}



double  dist_to_wall_x(t_player *p, int *step_x)
{
    double dist_to_side_x;
    
    if (p->ray_dir.x < 0)
	{
        dist_to_side_x = (p->pos_x - p->map_square_x) * delta_x(&p->ray_dir);
		*step_x += -1;
	}
    else
	{
        dist_to_side_x = (p->map_square_x + 1 - p->pos_x) * delta_x(&p->ray_dir);
		*step_x += 1;
	}
    return (dist_to_side_x);
}

double dist_to_wall_y(t_player *p, int *step_y)
{
    double dist_to_side_y;
    
    if (p->ray_dir.y < 0)
	{
        dist_to_side_y = (p->pos_y - p->map_square_y) * delta_y(&p->ray_dir);
		*step_y += -1;
	}
    else
	{
        dist_to_side_y = (p->map_square_y + 1 - p->pos_y) * delta_y(&p->ray_dir);
		*step_y += 1;
	}
    return (dist_to_side_y);
}

double dd_algth(void)
{
    double  dist_to_wallx;
    double  dist_to_wally;
	int     hit_side;
	
	t_player p;
	
	int step_x = 0;
	int step_y = 0;
	p.pos_y = 5;
	p.pos_x = 5;
	p.ray_dir.x = 1;
	p.ray_dir.y = 2.3;
	char map[10][10] = 
    {	//0    1    2    3    4    5    6    7    8    9
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, //0
        {'1', '0', '0', '0', '0', '0', '0', '0', '1', '1'}, //1
        {'1', '0', '0', '1', '1', '1', '1', '0', '1', '1'}, //2
        {'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //3
        {'1', '0', '1', '0', '0', '0', '0', '0', '1', '1'}, //4
        {'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //5
		{'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //6
		{'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'}, //7
		{'1', '0', '1', '0', '0', '0', '0', '0', '1', '1'}, //8
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}  //9
    };
	map_calc(&p);
	printf("map_square_x: %d\n", p.map_square_x);
	printf("map_square_y: %d\n", p.map_square_y);
	dist_to_wallx = dist_to_wall_x(&p, &p.step_x);
	dist_to_wally = dist_to_wall_y(&p, &p.step_y);
	printf("dist_to_wallx: %f\n", dist_to_wallx);
	printf("dist_to_wally: %f\n", dist_to_wally);
	p.step_x = 0;
	p.step_y = 0;
	while (map[p.map_square_y][p.map_square_x] != '1')
	{
		if (dist_to_wallx < dist_to_wally)
		{
			dist_to_wallx += dist_to_wall_x(&p, &p.step_x);
			printf("dist_to_wallx: %f\n", dist_to_wallx);
			p.map_square_x += p.step_x;
			hit_side = 0;
		}
		else
		{
			dist_to_wally += dist_to_wall_y(&p, &p.step_y);
			printf("dist_to_wally: %f\n", dist_to_wally);
			p.map_square_y += p.step_y;
			hit_side = 1;
		}
		printf("map_square_x: %d\n", p.map_square_x);
		printf("map_square_y: %d\n", p.map_square_y);
	}
	printf("map_square_x: %d\n", p.map_square_x);
	printf("map_square_y: %d\n", p.map_square_y);
	printf("hit_side: %d\n", hit_side);
	return	(0);
}

int main ()
{
	dd_algth();
	return (0);
}
