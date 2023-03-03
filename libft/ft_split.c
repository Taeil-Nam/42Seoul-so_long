/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:05:32 by tnam              #+#    #+#             */
/*   Updated: 2023/01/30 16:09:40 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_to_null(char const *str, char c, size_t str_len)
{
	size_t		i;
	char		*str_to_null;

	str_to_null = ft_strdup(str);
	if (str_to_null == 0)
		return (0);
	i = 0;
	while (i < str_len)
	{
		if (str_to_null[i] == c)
			str_to_null[i] = '\0';
		i++;
	}
	return (str_to_null);
}

static size_t	ft_sub_str_count(char *str_to_null, size_t str_len)
{
	size_t	sub_str_count;
	size_t	i;

	sub_str_count = 0;
	i = 0;
	while (i < str_len)
	{
		if ((str_to_null[i] != '\0') && (str_to_null[i + 1] == '\0'))
			sub_str_count++;
		i++;
	}
	return (sub_str_count);
}

static char	**ft_split_str(char *str_to_null, size_t str_len, char **result)
{
	size_t		i;
	size_t		sub_str_count;
	char		*sub_str;

	i = 0;
	sub_str_count = 0;
	while (i < str_len)
	{
		if (str_to_null[i] != '\0')
		{
			sub_str = ft_strdup(&str_to_null[i]);
			if (sub_str == 0)
			{
				while (--sub_str_count >= 0)
					free(result[sub_str_count]);
				free(result);
				return (0);
			}
			result[sub_str_count++] = sub_str;
			result[sub_str_count] = 0;
			i += ft_strlen(sub_str);
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t		str_len;
	size_t		sub_str_count;
	char		*str_to_null;
	char		**result;

	str_len = ft_strlen(s);
	str_to_null = ft_str_to_null(s, c, str_len);
	if (str_to_null == 0)
		return (0);
	sub_str_count = ft_sub_str_count(str_to_null, str_len);
	result = (char **)malloc((sub_str_count * sizeof(char *) + sizeof(char *)));
	if (result == 0)
	{
		free(str_to_null);
		return (0);
	}
	if (sub_str_count == 0)
	{
		result[0] = 0;
		free(str_to_null);
		return (result);
	}
	result = ft_split_str(str_to_null, str_len, result);
	free(str_to_null);
	return (result);
}
