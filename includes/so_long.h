/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:54:09 by tnam              #+#    #+#             */
/*   Updated: 2023/03/06 20:27:49 by tnam             ###   ########.fr       */
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

enum e_map
{
	FREE_SPACE = '0',
	WALL = '1',
	PLAYER = 'P',
	ESCAPE = 'E',
	COLLECTABLE = 'C'
};

typedef struct s_info
{
	int		argc;
	char	**argv;
	char	*map_file;
	int		map_fd;
	char	*map;
	int		map_size;
	int		map_row;
	int		map_col;
	char	*line;
}			t_info;

/* main */

/* init */
void	init_info(t_info *info, int argc, char **argv);

/* parse map1*/
void	parse_map(t_info *info);
void	get_map_size(t_info *info);
void	make_map(t_info *info);
void	check_is_valid_map(t_info *info);
void	check_can_escape(t_info *info);

/* parse map2*/
void	check_is_surrounding_walls(t_info *info, int i);
void	check_is_valid_count(int p_count, int e_count, int c_count);

/* parse map3*/
void	find_escape_path(t_info *info, int pos, bool *found_e, bool *visited);
void	find_path_up(t_info *info, int pos, bool *found_e, bool *visited);
void	find_path_right(t_info *info, int pos, bool *found_e, bool *visited);
void	find_path_down(t_info *info, int pos, bool *found_e, bool *visited);
void	find_path_left(t_info *info, int pos, bool *found_e, bool *visited);

/* error */
void	error_with_errno(void);
void	error_in_map1(char *type);
void	error_in_map2(char *type);

#endif