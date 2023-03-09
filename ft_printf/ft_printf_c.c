/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:15:28 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 15:50:39 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(va_list vargs_ptr)
{
	ft_putchar_fd((char)va_arg(vargs_ptr, int), 1);
	return (1);
}
