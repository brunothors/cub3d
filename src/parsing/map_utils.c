/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:40:21 by vcarrara          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	get_max_lines(t_data *data)
{
	int	lines;

	lines = 0;
	while (data->map[lines])
		lines++;
	data->lines = lines;
}

void	get_max_columns(t_data *data)
{
	int	max_columns;
	int	columns;
	int	i;

	max_columns = 0;
	i = 0;
	while (data->map[i])
	{
		columns = ft_strlen(data->map[i]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		i++;
	}
	data->columns = max_columns;
}

void	check_map_content(t_validate *valid)
{
	if (valid->invalid != 0)
		handle_error(WARNING_INVALID);
	else if (valid->player != 1)
		handle_error(WARNING_PLAYER);
}

int	check_invalid_char(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '\0'
		|| c == '\n' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
