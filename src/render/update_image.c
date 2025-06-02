/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:31:32 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	define_initial_plane(t_cub *game)
{
	if (game->data->pov_player == 'N')
	{
		game->dir = create_vector(0, -1);
		game->camera_plane = create_vector(0.66, 0);
	}
	else if (game->data->pov_player == 'S')
	{
		game->dir = create_vector(0, 1);
		game->camera_plane = create_vector(-0.66, 0);
	}
	else if (game->data->pov_player == 'W')
	{
		game->dir = create_vector(-1, 0);
		game->camera_plane = create_vector(0, -0.66);
	}
	else if (game->data->pov_player == 'E')
	{
		game->dir = create_vector(1, 0);
		game->camera_plane = create_vector(0, 0.66);
	}
}

void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player + 0.5,
			game->data->y_player + 0.5);
	define_initial_plane(game);
}

void	update_image(t_cub *game)
{
	static mlx_image_t	*fps_image;

	game->frame_time = game->mlx->delta_time;
	if (fps_image)
		mlx_delete_image(game->mlx, fps_image);
	fps_image = mlx_put_string(game->mlx, " ",
			WIDTH - 80, HEIGHT - 590);
}
