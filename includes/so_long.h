/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:54:09 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 15:30:30 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx_opengl/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <stdbool.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef struct s_info
{
	int		argc;
	char	**argv;
	int		map_fd;
	char	**map;
	int		map_row;
	int		map_col;
	char	*line;
}			t_info;

/* main */
void	error(void);

/* init */
void	init_info(t_info *info, int argc, char **argv);

/* parse map*/
void	parse_map(t_info *info);
void	get_map_size(t_info *info);
void	make_map(t_info *info);

#endif