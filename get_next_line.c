/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:32:17 by adubeau           #+#    #+#             */
/*   Updated: 2021/07/11 20:23:44 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_delstr(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_findN(char **str)
{
	int	len;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	return (len);
}

int	ft_retour(int ret, char **str, char **line)
{
	int		len;
	char	*temp;

	len = ft_findN(str);
	if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		temp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
		{
			ft_delstr(str);
			return (1);
		}
	}
	else
	{
		*line = ft_strdup(*str);
		ft_delstr(str);
	}
	if (ret == 0 && *str == NULL)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[100];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0 || fd < 0 || !line || BUFFER_SIZE <= 0)
			return (-1);
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ft_retour(ret, &str[fd], line));
}
