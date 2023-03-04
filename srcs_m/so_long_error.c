/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:34:04 by tnam              #+#    #+#             */
/*   Updated: 2023/03/04 16:46:02 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_with_errno(void)
{
	perror(NULL);
	exit(errno);
}

void	error_in_map1(char *type)
{
	if (ft_strncmp(type, "RECTANGLE", 9) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Not rectangle\n", 28);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "WALL", 4) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Not surrounding walls\n", 36);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "COMPONENT", 9) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid component is in file\n", 43);
		exit(EXIT_FAILURE);
	}
}

void	error_in_map2(char *type)
{
	if (ft_strncmp(type, "P_COUNT", 7) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid player count\n", 35);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "E_COUNT", 7) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid escape count\n", 35);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "C_COUNT", 7) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid collectable count\n", 40);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "NO_E_PATH", 9) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : There is no escape path\n", 38);
		exit(EXIT_FAILURE);
	}
}
