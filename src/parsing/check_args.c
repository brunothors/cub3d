/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:13:02 by vcarrara          #+#    #+#             */
/*   Updated: 2025/05/29 19:12:33 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	check_arguments(int argc)
{
	t_cub	*game;

	game = get_game(NULL);
	if (argc != 2)
	{
		printf(WARNING_ARGS);
		free_memory(game);
		exit(EXIT_FAILURE);
	}
}

void	check_extension(char *map_file)
{
	char	*extension;

	extension = strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".cub", 5) != 0)
	{
		handle_error(WARNING_EXT);
		exit(EXIT_FAILURE);
	}
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
