/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:35:31 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/02 23:34:33 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <limits.h>
# include <math.h>
# include "log_msg.h"
# include "libft.h"

# define PI 3.14159265358979323846

typedef struct s_game
{
    int         **map;
    int         game_w;
    int         game_h;
    t_player    player;
    
}			    t_game;

// o vector dos feixes de raios eh  direcao do jogador + plano da camera vezes um valor de -1 a 1 
// o plano eh perpendicular a direcao do jogador. A direcao do jogador intercepta o plano no ponto central da camera
// o multicador = 2*(x/width) - 1 ||| de -1 a 1
// DDAs (Digital Differential Analyzer)
typedef struct s_vector
{
    double  x;
    double  y;
}			t_vector;

typedef struct  s_position
{
    int x;
    int y;
}           t_position;

typedef struct s_player
{
    t_position  pos;
    t_vector    map_square;
    t_vector    direction;
    t_vector    plane;
    t_vector    ray_dir;
    t_vector   *ray_vector;
}			t_player;




#endif