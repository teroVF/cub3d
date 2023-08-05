/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:53:52 by antero            #+#    #+#             */
/*   Updated: 2023/08/05 14:54:09 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_MSG__H
# define LOG_MSG__H

/* COLORS */
/* ONLY USE FOR DEBUGGING */
# define DEF "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

/* ERROR MESSAGES */
# define INVALID_NBR_ARGS RED"Invalid number of arguments"DEF
# define NULL_MAP RED"NULL map argument"DEF
# define INVALID_MAP_FILE RED"Invalid map file"DEF
#endif