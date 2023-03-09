/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:19:41 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 15:49:30 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_x(unsigned int n, char *str, char format)
{
	int				i;
	unsigned int	div;
	unsigned int	mod;

	i = 0;
	while (1)
	{
		div = n / 16;
		mod = n % 16;
		if (format == 'x')
			str[i++] = "0123456789abcdef"[mod];
		else if (format == 'X')
			str[i++] = "0123456789ABCDEF"[mod];
		if (div <= 0)
			break ;
		n = div;
	}
	str[i] = '\0';
}

int	ft_printf_x(va_list vargs_ptr, char format)
{
	int				print_count;
	int				i;
	unsigned int	num;
	char			num_str[50];

	num = va_arg(vargs_ptr, unsigned int);
	ft_itoa_x(num, num_str, format);
	print_count = 0;
	i = (int)ft_strlen(num_str) - 1;
	while (i != -1)
	{
		write(1, &num_str[i], 1);
		i--;
		print_count++;
	}
	return (print_count);
}
