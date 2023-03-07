/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/03/07 19:00:16 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks()
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (EXIT_FAILURE);
	init_info(&info, argc, argv);
	check_map_file(&info);
	parse_map(&info);

	/* free zone */
	free(info.map);
	//atexit(leaks);
	return (0);
}
