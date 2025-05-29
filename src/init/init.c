/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:32:12 by bnespoli          #+#    #+#             */
/*   Updated: 2025/05/29 19:32:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	init_data(t_cub *game)
{
	game->data->size_textures = 0;
	game->data->no = NULL;
	game->data->so = NULL;
	game->data->we = NULL;
	game->data->ea = NULL;
	game->data->map = NULL;
	game->data->y_player = 0;
	game->data->x_player = 0;
	game->data->colors = false;
	game->data->floor = 0;
	game->data->ceiling = 0;
}

void	init_struct_variables(t_validate *valid)
{
	valid->invalid = 0;
	valid->player = 0;
}

void	init(t_cub *game)
{
	game->mlx = NULL;
	game->frame_time = 0;
	game->keys.w = false;
	game->keys.s = false;
	game->keys.a = false;
	game->keys.d = false;
	game->keys.left = false;
	game->keys.right = false;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->data = ft_calloc(1, sizeof(t_data));
	init_data(game);
	get_game(game);
}
