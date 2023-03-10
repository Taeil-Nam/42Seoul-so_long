/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_key_input_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:30:27 by tnam              #+#    #+#             */
/*   Updated: 2023/03/10 22:14:07 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_collect(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	game->player_pos -= game->map_col;
	game->player_row--;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, game->player_col * 64, game->player_row * 64);
	game->map[game->player_pos] = FREE_SPACE;
	game->collected_count++;
	ft_printf("You've collected %d objects, %d left.\n",
		game->collected_count,
		game->collect_goal_count - game->collected_count);
}

void	a_collect(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	game->player_pos -= 1;
	game->player_col--;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, game->player_col * 64, game->player_row * 64);
	game->map[game->player_pos] = FREE_SPACE;
	game->collected_count++;
	ft_printf("You've collected %d objects, %d left.\n",
		game->collected_count,
		game->collect_goal_count - game->collected_count);
}

void	s_collect(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	game->player_pos += game->map_col;
	game->player_row++;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, game->player_col * 64, game->player_row * 64);
	game->map[game->player_pos] = FREE_SPACE;
	game->collected_count++;
	ft_printf("You've collected %d objects, %d left.\n",
		game->collected_count,
		game->collect_goal_count - game->collected_count);
}

void	d_collect(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	game->player_pos += 1;
	game->player_col++;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->free_space, game->player_col * 64, game->player_row * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, game->player_col * 64, game->player_row * 64);
	game->map[game->player_pos] = FREE_SPACE;
	game->collected_count++;
	ft_printf("You've collected %d objects, %d left.\n",
		game->collected_count,
		game->collect_goal_count - game->collected_count);
}

void	check_can_finish_game(t_game *game)
{
	if (game->collected_count < game->collect_goal_count)
		ft_printf("You have to collect every collection in map!\n");
	else
	{
		ft_printf("========== You Win! ==========\n");
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->map);
		exit(EXIT_SUCCESS);
	}
}
