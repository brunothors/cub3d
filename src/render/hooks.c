/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:30:07 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	pressed(mlx_key_data_t keydata, t_cub *game);
static void	release(mlx_key_data_t keydata, t_cub *game);

void	hook_key_press(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		hook_close(game);
		return ;
	}
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		pressed(keydata, game);
	else if (keydata.action == MLX_RELEASE)
		release(keydata, game);
}

void	hook_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free_memory(game);
	mlx_close_window(game->mlx);
}

static void	pressed(mlx_key_data_t keydata, t_cub *game)
{
	if (keydata.key == MLX_KEY_W)
		game->keys.w = true;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = true;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = true;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = true;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left = true;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right = true;
}

static void	release(mlx_key_data_t keydata, t_cub *game)
{
	if (keydata.key == MLX_KEY_W)
		game->keys.w = false;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = false;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = false;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = false;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left = false;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right = false;
}
