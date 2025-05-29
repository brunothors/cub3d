/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:43:04 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 19:08:50 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	free_data(t_data *data)
{
	if (data->N)
		free(data->N);
	if (data->W)
		free(data->W);
	if (data->S)
		free(data->S);
	if (data->E)
		free(data->E);
	if (data->map)
		ft_free_matrix(data->map);
	if (data)
		free(data);
}

void	free_memory(t_cub *game)
{
	if (game->north)
		mlx_delete_texture(game->north);
	if (game->south)
		mlx_delete_texture(game->south);
	if (game->west)
		mlx_delete_texture(game->west);
	if (game->east)
		mlx_delete_texture(game->east);
	if (game)
		free_data(game->data);
}
