/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:55:01 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 19:12:33 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	store_map_line(bool *is_map, bool *map_ended, char *temp, int size)
{
	t_cub		*game;
	static int	i;

	game = get_game(NULL);
	if (*map_ended)
	{
		free(temp);
		handle_error(WARNING_MAP);
	}
	if (size >= game->data->size_textures)
	{
		game->data->map[i] = ft_strdup(temp);
		i++;
		*is_map = true;
	}
}

void	count_map_size(t_data *data, char *temp, int fd)
{
	int	map_size;

	map_size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map_size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (map_size == 0)
		handle_error(WARNING_MAP_SIZE);
	data->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!data->map)
		handle_error("Error: ft_calloc.\n");
}

void	read_and_copy_map_content(char *temp, int fd)
{
	int		size;
	bool	is_map;
	bool	map_ended;

	size = 0;
	is_map = false;
	map_ended = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] == '\n')
		{
			if (is_map && !map_ended)
				map_ended = true;
		}
		else
			store_map_line(&is_map, &map_ended, temp, size);
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

void	analyze_map_content(t_data *data, t_validate *valid)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_invalid_char(data->map[i][j]) == 0)
				valid->invalid++;
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				valid->player++;
				data->pov_player = data->map[i][j];
				data->y_player = i;
				data->x_player = j;
			}
			j++;
		}
		i++;
	}
}
