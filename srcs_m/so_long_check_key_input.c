/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_key_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:26 by tnam              #+#    #+#             */
/*   Updated: 2023/03/09 20:39:53 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_key_input(int key, t_game *game)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (key == W)
		key_w(game);
	else if (key == A)
		key_a(game);
	else if (key == S)
		key_s(game);
	else if (key == D)
		key_d(game);
	return (0);
}

void	key_w(t_game *game)
{
	if (game->map[game->player_pos - game->map_col] == WALL)
		return ;
	else if (game->map[game->player_pos - game->map_col] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos -= game->map_col;
		game->player_row--;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
		game->collected_count++;
		game->map[game->player_pos - game->map_col] = FREE_SPACE;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos -= game->map_col;
		game->player_row--;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
	}
	game->move_count++;
	ft_printf("Movement count = %d\n", game->move_count);
}

void	key_a(t_game *game)
{
	if (game->map[game->player_pos - 1] == WALL)
		return ;
	else if (game->map[game->player_pos - 1] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos -= 1;
		game->player_col--;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
		game->collected_count++;
		game->map[game->player_pos - game->map_col] = FREE_SPACE;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos -= 1;
		game->player_col--;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
	}
	game->move_count++;
	ft_printf("Movement count = %d\n", game->move_count);
}

void	key_s(t_game *game)
{
	if (game->map[game->player_pos + game->map_col] == WALL)
		return ;
	else if (game->map[game->player_pos + game->map_col] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos += game->map_col;
		game->player_row++;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
		game->collected_count++;
		game->map[game->player_pos - game->map_col] = FREE_SPACE;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos += game->map_col;
		game->player_row++;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
	}
	game->move_count++;
	ft_printf("Movement count = %d\n", game->move_count);
}

void	key_d(t_game *game)
{
	if (game->map[game->player_pos + 1] == WALL)
		return ;
	else if (game->map[game->player_pos + 1] == COLLECT)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos += 1;
		game->player_col++;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
		game->collected_count++;
		game->map[game->player_pos - game->map_col] = FREE_SPACE;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->free_space, game->player_col * 64, game->player_row * 64);
		game->player_pos += 1;
		game->player_col++;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, game->player_col * 64, game->player_row * 64);
	}
	game->move_count++;
	ft_printf("Movement count = %d\n", game->move_count);
}
