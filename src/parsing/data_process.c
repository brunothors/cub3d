/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:37:55 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 13:39:46 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	data_processing(char *map_file, t_data *data)
{
	char	*temp;
	int		fd;

	temp = NULL;
	fd = open_file(map_file);
	read_textures_path(data, temp, fd);
	count_map_size(data, temp, fd);
	fd = open_file(map_file);
	read_and_copy_map_content(temp, fd);
	if (data->map == NULL)
		handle_error(WARNING_MAP);
	get_max_columns(data);
	get_max_lines(data);
}

void	read_textures_path(t_data *data, char *temp, int fd)
{
	char	*line;

	temp = get_next_line(fd);
	while (temp)
	{
		line = temp;
		while (ft_isspace(*temp))
			temp++;
		read_textures_path_aux(data, temp, line);
		free(line);
		if (data->NO && data->SO && data->WE && data->EA && data->colors)
			break ;
		temp = get_next_line(fd);
	}
	if (!temp)
		handle_error(WARNING_INVALID_FILE);
}
