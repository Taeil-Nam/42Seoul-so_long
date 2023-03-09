/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:57:53 by tnam              #+#    #+#             */
/*   Updated: 2022/11/22 22:24:56 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return (result);
}
