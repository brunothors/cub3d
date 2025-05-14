/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:13:02 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/14 13:18:51 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_arguments(int argc)
{
	t_cub	*game;

	game = get_game(NULL);
	if (argc != 2)
	{
		printf(RED WARNING_ARGS RST);
		free_memory(game);
		exit(EXIT_FAILURE);
	}
}

void	check_extension(char *map_file)
{
	char	*extension;
	int		i;
	int		len;

	i = 0;
	extension = ".cub";
	len = ft_strlen(map_file);
	len = len - 4;
	while (map_file[len] && extension[i] && map_file[len] == extension[i])
	{
		i++;
		len++;
	}
	if (extension[i] == '\0')
		return ;
	handle_error(WARNING_EXT);
	exit(EXIT_FAILURE);
}

int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
