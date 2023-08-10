/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:28:49 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/10 11:49:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	exit_error(t_game *cub3d, char *msg)
{
	clean_game(cub3d);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	clean_game(t_game *cub3d)
{
	if (!cub3d)
		return ;
	if (cub3d->north)
		free (cub3d->north);
	if (cub3d->south)
		free (cub3d->south);
	if (cub3d->east)
		free (cub3d->east);
	if (cub3d->west)
		free (cub3d->west);
	if (cub3d->line)
		free (cub3d->line);
	if (cub3d->colors)
		free_split(cub3d->colors);
	if (cub3d->temp_map)
		free (cub3d->temp_map);
	if (cub3d->map)
		free_split(cub3d->map);
}

int	quit_game(t_game *cub3d)
{
	clean_game(cub3d);
	exit(EXIT_SUCCESS);
}
