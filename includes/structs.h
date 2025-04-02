/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:32:50 by vcarrara          #+#    #+#             */
/*   Updated: 2025/04/02 17:46:21 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* ************************************************************************** */
/*                                                                            */
/*                               PLAYER STRUCT                                */
/* Stores the player's position, direction, and camera plane.                 */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

/* ************************************************************************** */
/*                               TEXTURE STRUCT                               */
/* Holds the path, image pointer, and texture size.                           */
/* ************************************************************************** */

typedef struct s_texture
{
	void	*img;
	char	*path;
	int		*data;
	int		width;
	int		height;
}	t_texture;

/* ************************************************************************** */
/*                                MAP STRUCT                                  */
/* Stores the map grid and its dimensions.                                    */
/* ************************************************************************** */

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

/* ************************************************************************** */
/*                                MLX STRUCT                                  */
/* Contains MLX-related elements like window and image data.                  */
/* ************************************************************************** */

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

/* ************************************************************************** */
/*                                CUB STRUCT                                  */
/* The main structure holding all game data.                                  */
/* ************************************************************************** */

typedef struct s_cub
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
}	t_cub;

#endif
