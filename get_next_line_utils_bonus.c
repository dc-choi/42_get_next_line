/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:04:00 by donchoi           #+#    #+#             */
/*   Updated: 2022/03/07 17:01:16 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*substr;

	idx = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	s = s + start;
	while (*s)
	{
		if (idx < len)
		{
			substr[idx] = *s;
			idx++;
		}
		s++;
	}
	substr[idx] = '\0';
	return (substr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		idx;
	int		len1;
	int		len2;
	char	*str;

	idx = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[idx++] = *s1++;
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	int		len;
	int		idx;
	char	*new_str;

	idx = 0;
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (str[idx])
	{
		new_str[idx] = str[idx];
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
