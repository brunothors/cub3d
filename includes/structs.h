/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:32:50 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 14:33:31 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cube.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"

typedef struct s_data
{
	char			*NO;
	char			*WE;
	char			*SO;
	char			*EA;
	char			**map;
	bool			colors;
	uint32_t		floor;
	uint32_t		ceiling;
	int				size_textures;
	int				lines;
	int				columns;
	int				x_player;
	int				y_player;
	char			pov_player;
}	t_data;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l_arrow;
	bool	r_arrow;
}	t_keys;

typedef struct s_validate
{
	int		invalid;
	int		player;
}	t_validate;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_dda
{
	float		plane;
	t_vector	dir;
	t_vector	cam_pixel;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_vector	map;
	t_vector	step;
	int			side_hit;
	float		perp_dist;
	float		wall_hit_x;
}	t_dda;

typedef struct s_wall
{
	int		height;
	int		start;
	int		end;
	int		tex_x;
	int		tex_y;
	float	point_x;
	float	tex_step;
	float	tex_pos;
}	t_wall;

typedef struct s_cub
{
	mlx_t			*mlx;
	t_keys			keys;
	mlx_image_t		*mlx_image;
	mlx_texture_t	*texture;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				*texture_buffer[4];
	t_vector		pos;
	t_vector		dir;
	t_vector		camera_plane;
	int				hit_side;
	float			frame_time;
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
}	t_mlx_action;

#endif
