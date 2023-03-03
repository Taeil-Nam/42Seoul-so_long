/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:27:33 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 21:24:48 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_info *info)
{
	get_map_size(info);
	make_map(info);
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
			error2();
		info->map_row++;
		info->map_col = line_size;
		free(line);
	}
}

void	make_map(t_info *info)
{
	char	*line;

	info->map = (char **)malloc(info->map_row * info->map_col);
	if (info->map == NULL)
		exit(EXIT_FAILURE);
	if (close(info->map_fd) == ERROR)
		error1();
	info->map_fd = open(info->map_file, O_RDONLY);
	if (info->map_fd == ERROR)
		error1();
	info->map_row = 0;
	while (TRUE)
	{
		line = get_next_line(info->map_fd);
		if (line == NULL)
			break ;
		info->map[info->map_row] = ft_substr(line, 0, ft_strlen(line) - 1);
		printf("%s\n", info->map[info->map_row]);
		info->map_row++;
		free(line);
	}
	info->map[info->map_row] = NULL;
	printf("%p %s\n", &info->map[0], info->map[0]);
	printf("%p %s\n", &info->map[1], info->map[1]);
	printf("%p %s\n", &info->map[2], info->map[2]);
	printf("%p %s\n", &info->map[3], info->map[3]);
	printf("%p %s\n", &info->map[4], info->map[4]);
}
