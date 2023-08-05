/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:58:34 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 03:25:15 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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