/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:54:05 by tnam              #+#    #+#             */
/*   Updated: 2023/01/30 13:56:16 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursion(ssize_t new_n, int fd)
{
	char	c;

	if (new_n >= 10)
		ft_putnbr_recursion(new_n / 10, fd);
	c = (new_n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ssize_t	new_n;

	if (fd < 0)
		return ;
	new_n = n;
	if (new_n < 0)
	{
		new_n *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_recursion(new_n, fd);
}
