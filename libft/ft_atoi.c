/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:24:51 by tnam              #+#    #+#             */
/*   Updated: 2023/01/30 13:05:36 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		sign_count;
	int		result;

	i = 0;
	sign = 1;
	sign_count = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
		sign_count++;
		if (sign_count == 2)
			return (0);
	}
	while ('0' <= str[i] && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (sign * result);
}
