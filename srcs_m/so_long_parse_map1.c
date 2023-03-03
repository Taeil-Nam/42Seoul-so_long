/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:27:33 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 23:25:23 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_info *info)
{
	get_map_size(info);
	make_map(info);
	check_is_valid_map1(info);
	check_is_valid_map2(info);
}

void	get_map_size(t_info *info)
{
	char	*line;
	char	line_size;
	char	line_size_old;

	line_size_old = 0;
	while (TRUE)
	{
		line = get_next_line(info->map_fd);
		if (line == NULL)
			break ;
		line_size = ft_strlen(line);
		if (line_size_old == 0)
			line_size_old = line_size;
		if (line_size != line_size_old)
			error_in_map1("RECTANGLE");
		info->map_row++;
		info->map_col = line_size;
		free(line);
	}
}

void	make_map(t_info *info)
{
	char	*line;
	char	*line_old;

	info->map_size = info->map_row * info->map_col;
	info->map = (char *)malloc(1);
	if (info->map == NULL)
		exit(EXIT_FAILURE);
	info->map[0] = '\0';
	if (close(info->map_fd) == ERROR)
		error_with_errno();
	info->map_fd = open(info->map_file, O_RDONLY);
	if (info->map_fd == ERROR)
		error_with_errno();
	while (TRUE)
	{
		line = get_next_line(info->map_fd);
		if (line == NULL)
			break ;
		line_old = info->map;
		info->map = ft_strjoin(info->map, line);
		free(line_old);
		free(line);
	}
}

void	check_is_valid_map1(t_info *info)
{
	int			i;
	int			p_count;
	int			e_count;
	int			c_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (info->map[i] != '\0')
	{	
		if (info->map[i] != FREE_SPACE && info->map[i] != WALL
			&& info->map[i] != PLAYER && info->map[i] != ESCAPE
			&& info->map[i] != COLLECTABLE && info->map[i] != '\n')
			error_in_map1("COMPONENT");
		if (info->map[i] == PLAYER)
			p_count++;
		else if (info->map[i] == ESCAPE)
			e_count++;
		else if (info->map[i] == COLLECTABLE)
			c_count++;
		check_is_surrounding_walls(info, i);
		i++;
	}
	check_is_valid_count(p_count, e_count, c_count);
}

void	check_is_valid_map2(t_info *info)
{
	info->argc = 0; // dummy code.
	// To do:
	// - 플레이어 시작 지점부터 탈출 지점까지 갈 수 있는 길이 있는지 확인 하는 함수 구현.
}
