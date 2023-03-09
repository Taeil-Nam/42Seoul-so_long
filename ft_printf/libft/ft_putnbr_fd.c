/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:54:05 by tnam              #+#    #+#             */
/*   Updated: 2022/11/22 22:26:40 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_recursion(long long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_recursion(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	n_l;

	if (fd < 0)
		return ;
	n_l = (long long)n;
	if (n < 0)
	{
		n_l *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr_recursion(n_l, fd);
}
