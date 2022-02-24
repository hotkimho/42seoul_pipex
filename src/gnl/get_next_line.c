/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:01:19 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/23 18:53:41 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	find_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return ((int)i);
		i++;
	}
	return (-1);
}

int	split_newline(char **str, char **line)
{
	char	*tmp;
	int		line_size;
	size_t	last_size;

	line_size = find_newline(*str);
	if (line_size < 0)
	{
		last_size = ft_gnl_strlen(*str);
		*line = (char *)malloc(last_size + 1);
		if (line == NULL)
			return (0);
		ft_gnl_strlcpy(*line, *str, last_size + 1);
		free(*str);
		*str = NULL;
		return (0);
	}
	*line = (char *)malloc(line_size + 1);
	if (line == NULL)
		return (0);
	ft_gnl_strlcpy(*line, *str, (size_t)line_size + 1);
	tmp = ft_gnl_strdup(*str + line_size + 1);
	free(*str);
	*str = tmp;
	return (1);
}

int	read_all_file(char **str, char **line, int read_size)
{
	if (*str == NULL && read_size == 0)
	{
		*line = ft_gnl_strdup("");
		return (0);
	}
	if (split_newline(str, line))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_size == -1)
			return (-1);
		buf[read_size] = 0;
		str = ft_gnl_strjoin(str, buf);
		if (0 <= (read_size = find_newline(str)))
		{
			if (split_newline(&str, line) == 0)
				return (-1);
			return (1);
		}
	}
	return (read_all_file(&str, line, read_size));
}
