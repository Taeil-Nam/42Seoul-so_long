/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:34:47 by tnam              #+#    #+#             */
/*   Updated: 2023/01/30 14:27:28 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(const char *h, const char *n, size_t h_i, size_t len)
{
	size_t	n_i;

	n_i = 0;
	while (h_i < len)
	{
		if (n[n_i] == '\0')
			return (1);
		if (h[h_i] == '\0')
			return (0);
		if (h[h_i] != n[n_i])
			return (0);
		if ((n[n_i + 1] != '\0') && (h_i + 1 == len))
			return (0);
		h_i++;
		n_i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[i]);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
			if (isin(haystack, needle, i, len) == 1)
				return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
