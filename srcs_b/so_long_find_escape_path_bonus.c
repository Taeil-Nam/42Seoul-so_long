/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_escape_path_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:10 by tnam              #+#    #+#             */
/*   Updated: 2023/03/11 20:34:07 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_e_path(t_info *info, int pos, bool *found_e, bool *visited)
{
	visited[pos] = TRUE;
	if (visited[pos - info->map_col] == FALSE)
		find_e_path_up(info, pos, found_e, visited);
	if (visited[pos + 1] == FALSE)
		find_e_path_right(info, pos, found_e, visited);
	if (visited[pos + info->map_col] == FALSE)
		find_e_path_down(info, pos, found_e, visited);
	if (visited[pos - 1] == FALSE)
		find_e_path_left(info, pos, found_e, visited);
}

void	find_e_path_up(t_info *info, int pos, bool *found_e, bool *visited)
{
	if (info->map[pos - info->map_col] == ESCAPE)
	{
		*found_e = 1;
		return ;
	}
	else if (info->map[pos - info->map_col] == FREE_SPACE
		|| info->map[pos - info->map_col] == COLLECT)
		find_e_path(info, pos - info->map_col, found_e, visited);
}

void	find_e_path_right(t_info *info, int pos, bool *found_e, bool *visited)
{
	if (info->map[pos + 1] == ESCAPE)
	{
		*found_e = 1;
		return ;
	}
	else if (info->map[pos + 1] == FREE_SPACE
		|| info->map[pos + 1] == COLLECT)
		find_e_path(info, pos + 1, found_e, visited);
}

void	find_e_path_down(t_info *info, int pos, bool *found_e, bool *visited)
{
	if (info->map[pos + info->map_col] == ESCAPE)
	{
		*found_e = 1;
		return ;
	}
	else if (info->map[pos + info->map_col] == FREE_SPACE
		|| info->map[pos + info->map_col] == COLLECT)
		find_e_path(info, pos + info->map_col, found_e, visited);
}

void	find_e_path_left(t_info *info, int pos, bool *found_e, bool *visited)
{
	if (info->map[pos - 1] == ESCAPE)
	{
		*found_e = 1;
		return ;
	}
	else if (info->map[pos - 1] == FREE_SPACE
		|| info->map[pos - 1] == COLLECT)
		find_e_path(info, pos - 1, found_e, visited);
}
