/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:04:29 by adubeau           #+#    #+#             */
/*   Updated: 2021/07/08 12:13:41 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int ch)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = (char *)str;
	while (str[i] != '\0')
	{
		if ((char)str[i] == (char)ch)
			return (&str1[i]);
		i++;
	}
	if (ch == '\0')
		return (str1 + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && j < len)
	{
		str[j] = s[start + j];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
