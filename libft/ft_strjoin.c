/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:15:26 by tnam              #+#    #+#             */
/*   Updated: 2022/11/22 22:27:42 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	result_i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(((s1_len + s2_len) * sizeof(char)) + 1);
	if (result == 0)
		return (0);
	i = 0;
	result_i = 0;
	while (s1[i] != '\0')
		result[result_i++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result[result_i++] = s2[i++];
	result[result_i] = '\0';
	return (result);
}
