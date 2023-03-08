/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:54:09 by tnam              #+#    #+#             */
/*   Updated: 2023/03/08 16:10:46 by tnam             ###   ########.fr       */
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
	int		p_count;
	int		e_count;
	int		c_count;
	char	*line;
}			t_info;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
}			t_game;

/* main */

/* init */
void	init_info(t_info *info, int argc, char **argv);
void	check_map_file(t_info *info);

/* parse map*/
void	parse_map(t_info *info);
void	get_map_size(t_info *info);
void	make_map(t_info *info);
void	check_is_valid_map(t_info *info);

/* parse map utils*/
void	check_is_surrounding_walls(t_info *info, int i);
void	check_is_valid_count(t_info *info);
void	check_can_escape(t_info *info);
void	check_can_collectable(t_info *info);

/* find escape path*/
void	find_e_path(t_info *info, int pos, bool *found_e, bool *visited);
void	find_e_path_up(t_info *info, int pos, bool *found_e, bool *visited);
void	find_e_path_right(t_info *info, int pos, bool *found_e, bool *visited);
void	find_e_path_down(t_info *info, int pos, bool *found_e, bool *visited);
void	find_e_path_left(t_info *info, int pos, bool *found_e, bool *visited);

/* find collectable path*/
void	find_c_path(t_info *info, int pos, int *c_count, bool *visited);
void	find_c_path_up(t_info *info, int pos, int *c_count, bool *visited);
void	find_c_path_right(t_info *info, int pos, int *c_count, bool *visited);
void	find_c_path_down(t_info *info, int pos, int *c_count, bool *visited);
void	find_c_path_left(t_info *info, int pos, int *c_count, bool *visited);

/* game logic */
void	game_logic(t_info *info);
void	init_game(t_game *game);

/* error */
void	error_with_errno(void);
void	error_in_map1(char *type);
void	error_in_map2(char *type);
void	error_in_map3(char *type);
void	error_mlx(char *type);

#endif