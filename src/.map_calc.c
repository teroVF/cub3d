/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:38:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 03:34:29 by anvieira         ###   ########.fr       */
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
	int 	height;
	int 	width;
	double pos_x; //posicao do jogador no mapa
	double pos_y; //posicao do jogador no mapa
	int 	map_square_x; //quadrado do mapa em que o jogador esta
	int 	map_square_y; //quadrado do mapa em que o jogador esta
	t_vector ray_dir; //direcao do raio
	int step_x; //passos em x
	int step_y; //passos em y
	double size_ray; //tamanho do raio
	double tall_of_wall; //altura da parede
	double tall_of_wall_y1; //ponto 1
	double tall_of_wall_y2; //ponto 2
	
}               t_player;


double delta_x(t_vector *vector)
{
    //return (fabs(mag_vector(vector) / vector->x)); dividir por mag vector da 0
	return (1 / vector->x);
}

//tem de ser absoluto porque o delta eh sempre positivo. vr no fim
double delta_y(t_vector *vector)
{
    //return (fabs(mag_vector(vector) / vector->y)); dividir por mag vector da 0
	return (1 / vector->y);
}

void    map_position_square(t_player *player)
{
    player->map_square_x = floor(player->pos_x);
    player->map_square_y = floor(player->pos_y);
}



double  dist_to_wall_x(t_player *p)
{
    double dist_to_side_x;
    
    if (p->ray_dir.x < 0)
	{
        dist_to_side_x = (p->pos_x - p->map_square_x) * delta_x(&p->ray_dir);
		p->map_square_x += -1;
	}
    else
	{
        dist_to_side_x = (p->map_square_x + 1 - p->pos_x) * delta_x(&p->ray_dir);
		p->map_square_x += 1;
	}
    return (dist_to_side_x);
}

double dist_to_wall_y(t_player *p)
{
    double dist_to_side_y;
    
    if (p->ray_dir.y < 0)
	{
        dist_to_side_y = (p->pos_y - p->map_square_y) * delta_y(&p->ray_dir);
		p->map_square_y += -1;
	}
    else
	{
        dist_to_side_y = (p->map_square_y + 1 - p->pos_y) * delta_y(&p->ray_dir);
		p->map_square_y += 1;
	}
    return (dist_to_side_y);
}

double  perpendicular_dist_x(t_player *p, int step_x)
{
    double n;
    n = fabs(p->map_square_x - p->pos_x + ((1 - step_x) / 2));
    n = n / p->ray_dir.x;
    return (n);
}

double  perpendicular_dist_y(t_player *p, int step_y)
{
    double n;
    n = fabs(p->map_square_y - p->pos_y + ((1 - step_y) / 2));
    n = n / p->ray_dir.y;
    return (n);
}




double dd_algth(void)
{
    double  dist_to_wallx;
    double  dist_to_wally;
	int     hit_side;
	
	t_player p;
	p.height = 180;
	p.width = 320;
	p.pos_y = 5;
	p.pos_x = 5;
	p.ray_dir.x = 0.70710678118;
	p.ray_dir.y = 0.70710678118;
	
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
	map_calc(&p);
	////////////////////////
	if (p.ray_dir.x == 0)
	{
		dist_to_wallx = 1;
		dist_to_wally = 0;
	}
	else if (p.ray_dir.y == 0)
	{
		dist_to_wallx = 0;
		dist_to_wally = 1;		
	}
	else
	{	
		dist_to_wallx = dist_to_wall_x(&p);
		dist_to_wally = dist_to_wall_y(&p);
	}
	////////////////////////
	printf("dist_to_wallx: %f\n", dist_to_wallx);
	printf("dist_to_wally: %f\n", dist_to_wally);
	p.step_x = 0;
	p.step_y = 0;
	while (map[p.map_square_y][p.map_square_x] != '1')
	{
		////////////////////////
		if (p.ray_dir.x == 0)
		{
			dist_to_wallx = 1;
			dist_to_wally = 0;
		}
		else if (p.ray_dir.y == 0)
		{
			dist_to_wallx = 0;
			dist_to_wally = 1;		
		}
		////////////////////////
		if (dist_to_wallx < dist_to_wally)
		{
			dist_to_wallx += dist_to_wall_x(&p);
			p.map_square_x += p.step_x;
			hit_side = 0;
		}
		else
		{
			dist_to_wally += dist_to_wall_y(&p);
			p.map_square_y += p.step_y;
			hit_side = 1;
		}
		printf("map_square_x: %d\n", p.map_square_x);
		printf("map_square_y: %d\n", p.map_square_y);
	}
	printf("map_square_x: %d\n", p.map_square_x);
	printf("map_square_y: %d\n", p.map_square_y);
	printf("hit_side: %d\n", hit_side);
	if (hit_side == 0)
		p.size_ray = perpendicular_dist_x(&p, p.step_x);
	else
		p.size_ray = perpendicular_dist_y(&p, p.step_y);
	printf("size_ray: %f\n", p.size_ray);
	p.tall_of_wall = (p.height / p.size_ray);
	p.tall_of_wall_y1 = (p.height / 2) - (p.tall_of_wall / 2);
	p.tall_of_wall_y2 = (p.height / 2) + (p.tall_of_wall / 2);
	
	return	(0);
}

int main ()
{
	
	dd_algth();
	return (0);
}
