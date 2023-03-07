/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 21:07:15 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info, int argc, char **argv)
{
	info->argc = argc;
	info->argv = argv;
	info->map_file = argv[1];
	info->map_fd = open(info->map_file, O_RDONLY);
	if (info->map_fd == ERROR)
		error_with_errno();
	info->map = NULL;
	info->map_size = 0;
	info->map_row = 0;
	info->map_col = 0;
	info->p_count = 0;
	info->e_count = 0;
	info->c_count = 0;
	info->line = NULL;
}

void	check_map_file(t_info *info)
{
	int	i;

	i = 0;
	while (info->map_file[i] != '.')
		i++;
	if (ft_strncmp(&(info->map_file[i]), ".ber", 5) != 0)
		error_in_map1("FILENAME");
}
