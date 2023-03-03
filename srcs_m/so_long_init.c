/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 23:02:27 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	info->line = NULL;
}
