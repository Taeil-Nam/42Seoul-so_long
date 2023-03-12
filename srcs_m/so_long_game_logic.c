/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:13 by tnam              #+#    #+#             */
/*   Updated: 2023/03/09 22:27:05 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_logic(t_info *info)
{
	t_game	game;

	init_game1(&game, info);
	init_game2(&game);
	ft_printf("You have to collect all collectable object, ");
	ft_printf("%d left.\n", game.collect_goal_count - game.collected_count);
	render_map(info, &game);
	mlx_key_hook(game.mlx_win, check_key_input, &game);
	mlx_hook(game.mlx_win, ON_DESTROY, 0, close_game, &game);
	mlx_loop(game.mlx);
}

void	init_game1(t_game *game, t_info *info)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_mlx("MLX_INIT");
	game->pixel = 64;
	if ((info->map_col - 1) * game->pixel >= 2624
		|| info->map_row * game->pixel >= 1504)
		error_mlx("WINDOW_SIZE");
	game->mlx_win = mlx_new_window(game->mlx, (info->map_col - 1) * game->pixel,
			info->map_row * game->pixel, "so_long");
	if (game->mlx_win == NULL)
		error_mlx("MLX_WIN");
	game->collect_goal_count = info->c_count;
	game->collected_count = 0;
	game->move_count = 0;
	game->map = info->map;
	game->map_col = info->map_col;
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

int	close_game(t_game *game)
{
	free(game->map);
	exit(EXIT_SUCCESS);
}
