/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:34:04 by tnam              #+#    #+#             */
/*   Updated: 2023/03/03 20:37:03 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error1(void)
{
	perror(NULL);
	exit(errno);
}

void	error2(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, "Invalid map : not rectangle", 27);
	exit(EXIT_FAILURE);
}
