/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:25:53 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 15:49:44 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list vargs_ptr)
{
	int		len;
	char	*str;

	str = va_arg(vargs_ptr, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		return (len);
	}
}
