/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:47:51 by tnam              #+#    #+#             */
/*   Updated: 2022/12/06 16:12:17 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *a, ...);
int	ft_printf_c(va_list vargs_ptr);
int	ft_printf_s(va_list vargs_ptr);
int	ft_printf_p(va_list vargs_ptr);
int	ft_printf_d_i(va_list vargs_ptr);
int	ft_printf_u(va_list vargs_ptr);
int	ft_printf_x(va_list vargs_ptr, char format);
int	ft_printf_percent(void);

#endif