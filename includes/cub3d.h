/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:35:31 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/05 04:44:09 by anvieira         ###   ########.fr       */
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
# include "mlx.h"

# define PI 3.14159265358979323846


// o vector dos feixes de raios eh  direcao do jogador + plano da camera vezes um valor de -1 a 1 
// o plano eh perpendicular a direcao do jogador. A direcao do jogador intercepta o plano no ponto central da camera
// o multicador = 2*(x/width) - 1 ||| de -1 a 1
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
// DDAs (Digital Differential Analyzer)

typedef struct s_player
{
	t_vector    pos; //posicao do jogador no mapa
    t_vector    dir; //direcajogador
    t_vector    plane; //plano da camera
	t_position  map_square; //quadrado do mapa em que o jogador esta
	t_vector    ray_dir; //direcao do raio
	int         step_x; //passos em x
	int         step_y; //passos em y
	double      size_ray; //tamanho do raio
	double      tall_of_wall; //altura da parede
	double      tall_of_wall_y1; //ponto 1
	double      tall_of_wall_y2; //ponto 2
    int         hit_side; //0 = horizontal, 1 = vertical
    double      dist_to_wallx; //distancia ate a parede
    double      dist_to_wally; //distancia ate a parede
}
			t_player;
typedef struct s_game
{
    char         map[10][10];
    void        *mlx;
    void        *window;
    int         pixel;
    int         color_floor;
    int         color_ceiling;
    int         game_w;
    int         game_h;
    t_player    player;
    
}			    t_game;

//VETORES
double  perpendicular_dist_x(t_player *p, int step_x);
double  perpendicular_dist_y(t_player *p, int step_y);
double  dist_to_wall_y(t_player *p);
double  dist_to_wall_x(t_player *p);
void    dda(t_game *game);
int     create_background(t_game *g);


#endif