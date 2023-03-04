/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:08:07 by tnam              #+#    #+#             */
/*   Updated: 2023/03/04 16:57:53 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	check_is_valid_count(int p_count, int e_count, int c_count)
{
	if (p_count != 1)
		error_in_map2("P_COUNT");
	if (e_count != 1)
		error_in_map2("E_COUNT");
	if (c_count < 1)
		error_in_map2("C_COUNT");
}
