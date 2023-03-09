/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:13 by tnam              #+#    #+#             */
/*   Updated: 2023/03/09 11:41:42 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_logic(t_info *info)
{
	t_game	game;

	init_game1(&game);
	init_game2(&game);
	render_map(info, &game);
	mlx_key_hook(game.mlx_win, check_key_input, &game);
	mlx_hook(game.mlx_win, ON_DESTROY, 0, check_close_game, &game);
	mlx_loop(game.mlx);
}

void	init_game1(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_mlx("MLX_INIT");
	game->mlx_win = mlx_new_window(game->mlx, 1152, 896, "so_long");
	if (game->mlx_win == NULL)
		error_mlx("MLX_WIN");
	game->pixel = 64;
	game->current_c_count = 0;
}

void	init_game2(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/Wall.xpm",
			&(game->pixel), &(game->pixel));
	if (game->wall == NULL)
		error_mlx("MLX_XPM_LOAD");
	game->free_space = mlx_xpm_file_to_image(game->mlx,
			"textures/Free_space.xpm", &(game->pixel), &(game->pixel));
	if (game->free_space == NULL)
		error_mlx("MLX_XPM_LOAD");
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/Player.xpm", &(game->pixel), &(game->pixel));
	if (game->player == NULL)
		error_mlx("MLX_XPM_LOAD");
	game->escape = mlx_xpm_file_to_image(game->mlx,
			"textures/Escape.xpm", &(game->pixel), &(game->pixel));
	if (game->escape == NULL)
		error_mlx("MLX_XPM_LOAD");
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/Collect.xpm", &(game->pixel), &(game->pixel));
	if (game->collect == NULL)
		error_mlx("MLX_XPM_LOAD");
}
