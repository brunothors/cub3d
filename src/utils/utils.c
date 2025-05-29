/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:34:36 by bnespoli          #+#    #+#             */
/*   Updated: 2025/05/29 19:34:42 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: open file.\n");
	return (fd);
}

t_cub	*get_game(t_cub *game)
{
	static t_cub	*game_ptr;

	if (game)
		game_ptr = game;
	return (game_ptr);
}

void	handle_error(char *error)
{
	t_cub	*game;

	game = get_game(NULL);
	if (game)
		free_memory(game);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(RST, 2);
	exit(1);
}
