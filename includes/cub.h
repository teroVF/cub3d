/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:35:31 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/10 02:40:04 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "log_msg.h"
# include "libft.h"
# include "mlx.h"

# define PI 3.14159265358979323846

/* o vector dos feixes de raios eh  direcao do jogador + plano da camera vezes
um valor de -1 a 1 o plano eh perpendicular a direcao do jogador. A direcao do
jogador intercepta o plano no ponto central da camera o
multicador = 2*(x/width) - 1 ||| de -1 a 1 */
typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

typedef union u_distance
{
	double	dist_y;
	double	dist_x;
}			t_distance;

typedef union u_delta
{
	double	delta_y;
	double	delta_x;
}			t_deta;

typedef struct s_camera
{
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
}				t_camera;

typedef struct s_player
{
	t_vector	pos; //posicao do jogador no mapa
	t_vector	dir; //direcajogador
	t_vector	plane; //plano da camera
	t_position	map_square; //quadrado do mapa em que o jogador esta
	t_vector	ray_dir; //direcao do raio
	int			step_x; //passos em x
	int			step_y; //passos em y
	double		size_ray; //tamanho do raio
	double		tall_of_wall; //altura da parede
	int			tall_of_wall_y1; //ponto 1
	int			tall_of_wall_y2; //ponto 2
	int			hit_side; //0 = horizontal, 1 = vertical
	double		dist_to_side_x; //distancia ate a parede em x
	double		dist_to_side_y; //distancia ate a parede em y
	double		delta_dist_x;
	double		delta_dist_y;
}				t_player;
typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			pixel;
	int			color_floor;
	int			color_ceiling;
	int			game_w;
	int			game_h;
	t_player	player;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*line;
	char		**colors;
	int			ceiling;
	int			floor;
	int			start_map;
	char		*temp_map;
	char		spawn;
	char		**map;
	int			empty_line;
	t_data		frame;
}				t_game;

// utils.c
int			exit_error(t_game *cub3d, char *msg);
void		free_split(char **split);

// clean_exit.c
int			quit_game(t_game *cub3d);
void		clean_game(t_game *cub3d);

// parse.c
void		parse_file(t_game *cub3d, char *file);
void		parse_line(t_game *cub3d, char *line, int i);
void		check_color(t_game *cub3d, char *color, int face);
void		check_texture(t_game *cub3d, char *file, int face);

// parse_utils.c
int			have_numbers(char *str);
int			have_all_params(t_game *cub3d);
void		check_filename(t_game *cub3d, char *file, int mode);
void		check_texture_file(t_game *cub3d, char *file, int fd);
char		*get_value(char *line, int i, int mode);

// parse_map.c
void		parse_map(t_game *cub3d, int fd);
int			is_surrounded_by_walls(t_game *cub3d, int direction, int i, int j);
void		check_map(t_game *cub3d, int i, int j);
void		parse_map_line(t_game *cub3d, char *line);
int			is_empty_line(t_game *cub3d, char *line);

//render
int			create_background(t_game *g);

// raycasting
t_vector	mult_vector(t_vector *v, double n);
t_vector	add_vector(t_vector *v1, t_vector *v2);
double		perpendicular_dist_x(t_player *p, int step_x);
double		perpendicular_dist_y(t_player *p, int step_y);
double		dist_to_wall_y(t_player *p);
double		dist_to_wall_x(t_player *p);
int			rayscasting(t_game *g);
void		map_position_square(t_player *player);
void		calculate_delta(t_game *g);
void		dda(t_game *g);
void		calculate_distance(t_game *g);
void		calculate_height_wall(t_game *game);
int			create_background(t_game *g);

//init
int			end_game(t_game *game);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);

//hooks
int			read_keys(int keypress, t_game *game);
int			render_game(t_game *cub3d);

// player_position.c
void		rotate_vector(t_vector *v, double angle);
void		set_direction(t_game *cub3d);
void		set_player_position(t_game *cub3d, int i, int j);

#endif