# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by tnam              #+#    #+#              #
#    Updated: 2023/03/03 23:08:35 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
RM				=	rm -f

LIBFT_DIR		=	libft/
LIBFT			=	libft.a
LIBFT_C			=	-L$(LIBFT_DIR) -lft

MLX_DIR			=	mlx_opengl/
MLX				=	libmlx.a
MLX_C			=	-L$(MLX_DIR) -lmlx

INCLUDES		=	includes/

SRCS_M			=	srcs_m/so_long_main.c				\
					srcs_m/so_long_init.c				\
					srcs_m/so_long_parse_map1.c			\
					srcs_m/so_long_parse_map2.c			\
					srcs_m/so_long_error.c				\
					gnl/get_next_line.c					\
					gnl/get_next_line_utils.c			\
									
SRCS_B			=	
					
OBJS_M			=	$(SRCS_M:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

BONUS_MODE = $(findstring $(MAKECMDGOALS),bonus)

ifeq ($(BONUS_MODE), )
    OBJS = $(OBJS_M)
else
    OBJS = $(OBJS_B)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFT_C) $(MLX_C) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all bonus clean fclean re