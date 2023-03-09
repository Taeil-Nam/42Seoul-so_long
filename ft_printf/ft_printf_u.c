/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:06:57 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 15:49:36 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_u_recursion(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_u_recursion(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	ft_printf_u(va_list vargs_ptr)
{
	int				print_count;
	unsigned int	num;

	num = va_arg(vargs_ptr, unsigned int);
	ft_putnbr_u_recursion(num, 1);
	print_count = 0;
	if (num == 0)
		print_count = 1;
	while (num != 0)
	{
		num /= 10;
		print_count++;
	}
	return (print_count);
}
