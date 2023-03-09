/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:14:45 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 15:49:16 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_vargs(const char *format, va_list vargs_ptr);

int	ft_printf(const char *a, ...)
{
	int			i;
	int			print_count;
	va_list		vargs_ptr;

	va_start(vargs_ptr, a);
	i = 0;
	print_count = 0;
	while (a[i])
	{
		if (a[i] != '%')
		{
			write(1, &a[i], 1);
			i++;
			print_count++;
		}
		else
		{
			print_count += ft_print_vargs(&a[i] + 1, vargs_ptr);
			i += 2;
		}
	}
	va_end(vargs_ptr);
	return (print_count);
}

int	ft_print_vargs(const char *format, va_list vargs_ptr)
{
	int	print_count;

	print_count = 0;
	if (*format == 'c')
		print_count = ft_printf_c(vargs_ptr);
	else if (*format == 's')
		print_count = ft_printf_s(vargs_ptr);
	else if (*format == 'p')
		print_count = ft_printf_p(vargs_ptr);
	else if (*format == 'd' || *format == 'i')
		print_count = ft_printf_d_i(vargs_ptr);
	else if (*format == 'u')
		print_count = ft_printf_u(vargs_ptr);
	else if (*format == 'x' || *format == 'X')
		print_count = ft_printf_x(vargs_ptr, *format);
	else if (*format == '%')
		print_count = ft_printf_percent();
	return (print_count);
}
