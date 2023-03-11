/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_collect_path_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:57:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/11 20:34:04 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_c_path(t_info *info, int pos, int *c_count, bool *visited)
{
	visited[pos] = TRUE;
	if (visited[pos - info->map_col] == FALSE)
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
	if (info->map[pos - info->map_col] == COLLECT)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos - info->map_col] == FREE_SPACE)
		find_c_path(info, pos - info->map_col, c_count, visited);
}

void	find_c_path_right(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos + 1] == COLLECT)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos + 1] == FREE_SPACE)
		find_c_path(info, pos + 1, c_count, visited);
}

void	find_c_path_down(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos + info->map_col] == COLLECT)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos + info->map_col] == FREE_SPACE
		|| info->map[pos + info->map_col] == COLLECT)
		find_c_path(info, pos + info->map_col, c_count, visited);
}

void	find_c_path_left(t_info *info, int pos, int *c_count, bool *visited)
{
	if (info->map[pos - 1] == COLLECT)
	{
		*c_count += 1;
		find_c_path(info, pos - info->map_col, c_count, visited);
	}
	else if (info->map[pos - 1] == FREE_SPACE
		|| info->map[pos - 1] == COLLECT)
		find_c_path(info, pos - 1, c_count, visited);
}
