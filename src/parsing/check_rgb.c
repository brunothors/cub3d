/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:12:37 by vcarrara          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	handle_error_rgb(char *original, char **rgb)
{
	free(original);
	ft_free_matrix(rgb);
	handle_error(WARNING_INVALID_COLOR);
}

static void	control_characters(char *rgb_color, char *original, char c)
{
	int	qtd;
	int	space;

	qtd = 0;
	space = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
	{
		if (*rgb_color == c)
			qtd++;
		if (ft_isspace(*rgb_color))
			space++;
		rgb_color++;
	}
	if (qtd != 1 || space < 1)
	{
		free(original);
		handle_error(WARNING_INVALID_COLOR);
	}
}

void	check_rgb(uint32_t *color, char *rgb_color, char *original, char c)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	control_characters(rgb_color, original, c);
	split_rgb(&rgb, rgb_color, original, c);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				handle_error_rgb(original, rgb);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			handle_error_rgb(original, rgb);
		i++;
	}
	*color = convert_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_matrix(rgb);
}

static int	valid_rgb_content(char *rgb_color)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (rgb_color[i])
	{
		if (rgb_color[i] >= '0' && rgb_color[i] <= '9')
			valid = 1;
		i++;
	}
	return (valid);
}

void	split_rgb(char ***rgb, char *rgb_color, char *original, char c)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
	{
		free(original);
		handle_error(WARNING_INVALID_COLOR);
	}
	while ((*rgb)[i])
	{
		temp_strim = ft_strtrim((*rgb)[i], " \t\v\f\r\n\b");
		free((*rgb)[i]);
		(*rgb)[i] = temp_strim;
		if (ft_strncmp((*rgb)[i], "\n", 1) == 0 || ft_isspace((*rgb)[i][0]))
			handle_error_rgb(original, *rgb);
		if (valid_rgb_content((*rgb)[i]) == 0)
			handle_error_rgb(original, *rgb);
		i++;
	}
	if (i != 3)
		handle_error_rgb(original, *rgb);
}
