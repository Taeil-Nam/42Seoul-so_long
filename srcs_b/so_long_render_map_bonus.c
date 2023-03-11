/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:04 by tnam              #+#    #+#             */
/*   Updated: 2023/03/11 20:34:22 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map(t_info *info, t_game *game)
{
	render_tile(info, game);
	render_player(info, game);
	render_escape(info, game);
	render_collect(info, game);
}

void	render_tile(t_info *info, t_game *game)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	col = 0;
	row = 0;
	while (info->map[i] != '\0')
	{
		if (info->map[i] == WALL)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->wall, col * 64, row * 64);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->free_space, col * 64, row * 64);
		i++;
		col++;
		if (col % info->map_col == 0)
		{
			col = 0;
			row++;
		}
	}
}

void	render_player(t_info *info, t_game *game)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	col = 0;
	row = 0;
	while (info->map[i] != '\0')
	{
		if (info->map[i] == PLAYER)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->player, col * 64, row * 64);
			game->player_pos = i;
			game->player_col = col;
			game->player_row = row;
		}
		i++;
		col++;
		if (col % info->map_col == 0)
		{
			col = 0;
			row++;
		}
	}
}

void	render_escape(t_info *info, t_game *game)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	col = 0;
	row = 0;
	while (info->map[i] != '\0')
	{
		if (info->map[i] == ESCAPE)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->escape, col * 64, row * 64);
		}
		i++;
		col++;
		if (col % info->map_col == 0)
		{
			col = 0;
			row++;
		}
	}
}

void	render_collect(t_info *info, t_game *game)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	col = 0;
	row = 0;
	while (info->map[i] != '\0')
	{
		if (info->map[i] == COLLECT)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->collect, col * 64, row * 64);
		i++;
		col++;
		if (col % info->map_col == 0)
		{
			col = 0;
			row++;
		}
	}
}
