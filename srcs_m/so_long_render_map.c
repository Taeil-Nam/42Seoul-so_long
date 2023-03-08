/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:13:04 by tnam              #+#    #+#             */
/*   Updated: 2023/03/08 21:52:46 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_info *info, t_game *game)
{
	render_tile(info, game);
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
		else if (info->map[i] == FREE_SPACE)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->free_space, col * 64, row * 64);
		i++;
		col++;
		if (col % 19 == 0)
		{
			col = 0;
			row++;
		}
	}
}
