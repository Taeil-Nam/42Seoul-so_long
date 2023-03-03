/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:53:34 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 21:21:42 by tnam             ###   ########.fr       */
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
	// printf("%p %s\n", &info.map[0], info.map[0]);
	// printf("%p %s\n", &info.map[1], info.map[1]);
	// printf("%p %s\n", &info.map[2], info.map[2]);
	// printf("%p %s\n", &info.map[3], info.map[3]);
	// printf("%p %s\n", &info.map[4], info.map[4]);
	
	/* free zone */
	// for (int i = 0; i < 5; i++)
	// 	free(info.map[i]);
	free(info.map);
	//atexit(leaks);
	return (0);
}
