/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:26:09 by vcarrara          #+#    #+#             */
/*   Updated: 2025/06/02 17:36:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	check_colors(t_data *data, char *line, char *temp)
{
	static int	ceiling;
	static int	floor;

	if (ft_strncmp("F", temp, 1) == 0)
		floor++;
	if (ft_strncmp("C", temp, 1) == 0)
		ceiling++;
	if (ceiling == 1 && floor == 1)
		data->colors = true;
	if (ceiling > 1 || floor > 1)
	{
		free(line);
		handle_error(WARNING_DUP_COLOR);
	}
}

void	read_textures_path_aux(t_data *data, char *temp, char *line)
{
	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(data->no), temp, "NO", line);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(data->so), temp, "SO", line);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(data->we), temp, "WE", line);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(data->ea), temp, "EA", line);
	else if (ft_strncmp("F", temp, 1) == 0)
		check_rgb(&data->floor, temp, line, 'F');
	else if (ft_strncmp("C", temp, 1) == 0)
		check_rgb(&data->ceiling, temp, line, 'C');
	else
	{
		if (temp[0] != '\n' && temp[0] != '\0')
		{
			free(line);
			handle_error(WARNING_INVALID_FILE);
		}
	}
	check_colors(data, line, temp);
	data->size_textures++;
}

void	copy_texture_path(char **texture, char *path, char *mode,
	char *line)
{
	int		size_key;

	size_key = 0;
	if (*texture != NULL)
	{
		free(line);
		handle_error(WARNING_DUP_TEXTURE);
	}
	check_spaces(path, mode, line);
	while (ft_isspace(*path) || ft_strncmp(mode, path, 2) == 0)
	{
		if (ft_strncmp(mode, path, 2) == 0)
		{
			size_key++;
			path++;
		}
		path++;
	}
	trim_newline(path, line);
	if (!check_path(path) || size_key != 1)
	{
		free(line);
		handle_error(WARNING_TEXTURE);
	}
	*texture = ft_strdup(path);
}

void	trim_newline(char *str, char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
	{
		len++;
		i++;
	}
	if (str[i] != '\0' && str[i] != '\n')
	{
		free(line);
		handle_error(WARNING_TEXTURE);
	}
	str[i - len] = '\0';
}

void	check_spaces(char *temp, char *mode, char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(mode, temp, 2) == 0)
		i += 2;
	if (ft_isspace(temp[i]))
		return ;
	else
	{
		free(line);
		handle_error(WARNING_TEXTURE);
	}
}
