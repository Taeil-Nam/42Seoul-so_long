/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 23:00:44 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

	// To do 1: 맵 파싱하기.
	parse_map(&info);

	// To do 2: 게임 로직 만들기.
	//printf("%s\n", info.map);

	/* free zone */
	free(info.map);
	atexit(leaks);
	return (0);
}
