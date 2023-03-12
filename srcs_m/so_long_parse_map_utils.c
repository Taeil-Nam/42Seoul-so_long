/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:08:07 by tnam              #+#    #+#             */
/*   Updated: 2023/03/09 11:39:46 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_is_surrounding_walls(t_info *info, int i)
{
	if (i < info->map_col - 1 && info->map[i] != WALL)
		error_in_map1("WALL");
	else if (info->map[i] != 0 && (info->map[i - 1] == '\n'
			|| info->map[i + 1] == '\n') && info->map[i] != WALL)
		error_in_map1("WALL");
	else if (info->map_size - info->map_col <= i
		&& i < info->map_size - 1 && info->map[i] != WALL)
		error_in_map1("WALL");
}

void	check_is_valid_count(t_info *info)
{
	if (info->p_count != 1)
		error_in_map2("P_COUNT");
	if (info->e_count != 1)
		error_in_map2("E_COUNT");
	if (info->c_count < 1)
		error_in_map2("C_COUNT");
}

void	check_can_collect(t_info *info)
{
	int		player_pos;
	int		c_count;
	bool	*visited;

	player_pos = 0;
	c_count = 0;
	visited = (bool *)ft_calloc(info->map_size, sizeof(int));
	if (visited == NULL)
		exit(EXIT_FAILURE);
	while (info->map[player_pos] != PLAYER)
		player_pos++;
	find_c_path(info, player_pos, &c_count, visited);
	free(visited);
	if (c_count < info->c_count)
		error_in_map3("NO_C_PATH");
}

void	check_can_escape(t_info *info)
{
	int		player_pos;
	bool	found_e;
	bool	*visited;

	player_pos = 0;
	found_e = 0;
	visited = (bool *)ft_calloc(info->map_size, sizeof(int));
	if (visited == NULL)
		exit(EXIT_FAILURE);
	while (info->map[player_pos] != PLAYER)
		player_pos++;
	find_e_path(info, player_pos, &found_e, visited);
	free(visited);
	if (found_e == 0)
		error_in_map2("NO_E_PATH");
}
