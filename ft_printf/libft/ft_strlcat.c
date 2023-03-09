/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:59:42 by tnam              #+#    #+#             */
/*   Updated: 2022/11/17 22:36:02 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	j = 0;
	if (dst_len <= dstsize)
	{
		while (src[j] && (dst_len + j + 1 < dstsize))
		{
			dst[i++] = src[j++];
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	else
		return (dstsize + src_len);
}
