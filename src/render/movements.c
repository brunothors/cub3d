/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:30:40 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	process_input(t_cub *game)
{
	float	new_x;
	float	new_y;
	float	lerp_factor;

	new_x = 0;
	new_y = 0;
	lerp_factor = 1;
	calculate_new_position(game, &new_x, &new_y);
	if (can_move_to(game, new_x, new_y))
	{
		game->pos.x = game->pos.x + lerp_factor * (new_x - game->pos.x);
		game->pos.y = game->pos.y + lerp_factor * (new_y - game->pos.y);
	}
	if (game->keys.left)
	{
		game->dir = rotate_vector(game->dir, -1.5);
		game->camera_plane = rotate_vector(game->camera_plane, -1.5);
	}
	if (game->keys.right)
	{
		game->dir = rotate_vector(game->dir, 1.5);
		game->camera_plane = rotate_vector(game->camera_plane, 1.5);
	}
}

int	get_signal(float value)
{
	if (value < 0)
		return (-1);
	return (1);
}

bool	can_move_to(t_cub *game, float new_x, float new_y)
{
	float	margin;

	margin = 0.1;
	if (game->data->map[(int)(new_y + margin
			* get_signal(new_y - game->pos.y))][(int)new_x] == '1')
		return (false);
	if (game->data->map[(int)new_y][(int)(new_x + margin
		* get_signal(new_x - game->pos.x))] == '1')
		return (false);
	if (game->data->map[(int)(new_y + margin
			* get_signal(game->camera_plane.y))][(int)new_x] == '1')
		return (false);
	if (game->data->map[(int)new_y][(int)(new_x + margin
		* get_signal(game->camera_plane.x))] == '1')
		return (false);
	return (true);
}

void	calculate_new_position(t_cub *game, float *new_x, float *new_y)
{
	float	move_speed;

	move_speed = game->frame_time * 4;
	*new_x = game->pos.x;
	*new_y = game->pos.y;
	if (game->keys.w == true)
	{
		*new_x += game->dir.x * move_speed;
		*new_y += game->dir.y * move_speed;
	}
	if (game->keys.s == true)
	{
		*new_x -= game->dir.x * move_speed;
		*new_y -= game->dir.y * move_speed;
	}
	if (game->keys.a == true)
	{
		*new_x -= game->camera_plane.x * move_speed;
		*new_y -= game->camera_plane.y * move_speed;
	}
	if (game->keys.d == true)
	{
		*new_x += game->camera_plane.x * move_speed;
		*new_y += game->camera_plane.y * move_speed;
	}
}
