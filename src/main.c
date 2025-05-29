/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:22:43 by bnespoli          #+#    #+#             */
/*   Updated: 2025/05/29 19:23:01 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init(&game);
	parsing(argc, argv, &game);
	printf("PARSING OK\n");
	init_game(&game);
	return (EXIT_SUCCESS);
}
