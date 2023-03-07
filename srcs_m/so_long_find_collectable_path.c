/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_collectable_path.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:57:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 21:25:44 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_c_path(t_info *info, int pos, int *c_count, bool *visited)
{
	visited[pos] = TRUE;
	if (visited[pos - info->map_col] == FALSE && pos - info->map_col >= 0)
		find_c_path_up(info, pos, c_count, visited);
	if (visited[pos + 1] == FALSE)
		find_c_path_right(info, pos, c_count, visited);
	if (visited[pos + info->map_col] == FALSE)
		find_c_path_down(info, pos, c_count, visited);
	if (visited[pos - 1] == FALSE)
		find_c_path_left(info, pos, c_count, visited);
}

void	find_c_path_up(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos - info->map_col] == COLLECTABLE)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos - info->map_col] == FREE_SPACE)
		find_c_path(info, pos - info->map_col, c_count, visited);
}

void	find_c_path_right(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos + 1] == COLLECTABLE)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos + 1] == FREE_SPACE)
		find_c_path(info, pos + 1, c_count, visited);
}

void	find_c_path_down(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos + info->map_col] == COLLECTABLE)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos + info->map_col] == FREE_SPACE
		|| info->map[pos + info->map_col] == COLLECTABLE)
		find_c_path(info, pos + info->map_col, c_count, visited);
}

void	find_c_path_left(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos - 1] == COLLECTABLE)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos - 1] == FREE_SPACE
		|| info->map[pos - 1] == COLLECTABLE)
		find_c_path(info, pos - 1, c_count, visited);
}
