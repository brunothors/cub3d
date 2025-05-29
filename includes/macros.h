/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:35:42 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 15:22:36 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cube.h"

# define WIDTH 800
# define HEIGHT 600
# define ROTATE_LEFT -0.5
# define ROTATE_RIGHT 0.5
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define WARNING_ARGS "Error: Number of arguments is invalid.\n"
# define WARNING_EXT "Error: The map file must be .cub\n"
# define WARNING_PLAYER "Error: Invalid player.\n"
# define WARNING_INVALID "Error: Invalid character in map.\n"
# define WARNING_EMPTY_LINE "Error: Empty line.\n"
# define WARNING_OPEN_MAP "Error: Map is open.\n"
# define WARNING_TEXTURE "Error: Invalid texture path.\n"
# define WARNING_DUP_COLOR "Error: Duplicated color.\n"
# define WARNING_DUP_TEXTURE "Error: Duplicated texture.\n"
# define WARNING_INVALID_FILE "Error: Invalid file.\n"
# define WARNING_INVALID_COLOR "Error: Invalid RGB color.\n"
# define WARNING_EDGE_MAP "Error: Map is not surrounded by walls.\n"
# define WARNING_MAP "Error: Invalid map.\n"
# define WARNING_MAP_SIZE "Error: Invalid map size.\n"

#endif
