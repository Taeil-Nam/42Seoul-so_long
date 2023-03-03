/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:48:43 by tnam              #+#    #+#             */
/*   Updated: 2023/01/30 16:12:52 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (len < s_len)
		result = (char *)malloc((len * sizeof(char)) + 1);
	else
		result = (char *)malloc((s_len * sizeof(char)) + 1);
	if (result == 0)
		return (0);
	i = 0;
	while ((i < len) && (start + i < s_len))
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
