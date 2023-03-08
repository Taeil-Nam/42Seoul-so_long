/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:13 by tnam              #+#    #+#             */
/*   Updated: 2023/03/08 16:17:40 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_logic(t_info *info)
{
	t_game	game;

	init_game(&game);
	mlx_loop(game.mlx);
	info->argc = 0; // dummy
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_mlx("MLX_INIT");
	game->mlx_win = mlx_new_window(game->mlx, 1600, 900, "so_long");
	if (game->mlx_win == NULL)
		error_mlx("MLX_WIN");
}
