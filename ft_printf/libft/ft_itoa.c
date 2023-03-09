/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:53:34 by tnam              #+#    #+#             */
/*   Updated: 2022/11/30 11:43:25 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getlen(int n)
{
	size_t	len;

	if (n == 0)
	{
		return (1);
	}
	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	div;
	char		*result;

	len = ft_getlen(n);
	div = (long long)n;
	result = malloc((len * sizeof(char)) + 1);
	if (result == 0)
		return (0);
	if (div < 0)
	{
		result[0] = '-';
		div *= -1;
	}
	if (div == 0)
		result[0] = '0';
	result[len] = 0;
	len -= 1;
	while (div != 0)
	{
		result[len] = (div % 10) + '0';
		len--;
		div /= 10;
	}
	return (result);
}
