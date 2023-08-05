/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:49:56 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/01 01:54:02 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	valid_cub(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".cub", &map_file[i], 4) == 0)
		return (1);
	return (0);
}

void	error_msg(char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
    return (EXIT_FAILURE);
}