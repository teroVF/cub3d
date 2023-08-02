/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:58:34 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/02 23:21:51 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

