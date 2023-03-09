/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:34:04 by tnam              #+#    #+#             */
/*   Updated: 2023/03/09 11:38:14 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_with_errno(void)
{
	perror(NULL);
	exit(errno);
}

void	error_in_map1(char *type)
{
	if (ft_strncmp(type, "FILENAME", 9) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "The file has an invalid extension.\n", 35);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "RECTANGLE", 10) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Not rectangle.\n", 29);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "WALL", 5) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Not surrounding walls.\n", 37);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "COMPONENT", 10) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid component in file.\n", 41);
		exit(EXIT_FAILURE);
	}
}

void	error_in_map2(char *type)
{
	if (ft_strncmp(type, "P_COUNT", 8) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid player count.\n", 36);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "E_COUNT", 8) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid escape count.\n", 36);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "C_COUNT", 8) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : Invalid collect count.\n", 37);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "NO_E_PATH", 10) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : There is no escape path.\n", 39);
		exit(EXIT_FAILURE);
	}
}

void	error_in_map3(char *type)
{
	if (ft_strncmp(type, "NO_C_PATH", 10) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "Invalid map : There is no collect path.\n", 39);
		exit(EXIT_FAILURE);
	}
}

void	error_mlx(char *type)
{
	if (ft_strncmp(type, "MLX_INIT", 9) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "mlx_init() failed.\n", 19);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "MLX_WIN", 8) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "mlx_new_window() failed.\n", 25);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(type, "MLX_XPM_LOAD", 13) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, "mlx_xpm_file_to_image() failed.\n", 32);
		exit(EXIT_FAILURE);
	}
}
