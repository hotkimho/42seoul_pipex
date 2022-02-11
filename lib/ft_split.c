/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:40:00 by hkim2             #+#    #+#             */
/*   Updated: 2021/06/02 15:58:26 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_error(char **s)
{
	int			i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

static int		find_size(char const *s, char c)
{
	size_t			i;
	int			count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static void		ft_strcpy(char *dest, char const *src, int start, int end)
{
	int			i;

	i = 0;
	while (start < end)
		dest[i++] = src[start++];
	dest[i] = 0;
}

char			**ft_split(char const *s, char c)
{
	char			**split_s;
	int				s_size;
	size_t			i;
	int				start;

	if (!s)
		return (NULL);
	s_size = find_size(s, c) + 1;
	if (!(split_s = (char **)malloc(sizeof(char *) * s_size)))
		return (NULL);
	i = -1;
	start = 0;
	s_size = 0;
	while (++i < ft_strlen(s))
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(split_s[s_size] = (char *)malloc(i - start + 1)))
				return (ft_error(split_s));
			ft_strcpy(split_s[s_size++], s, start, i);
		}
	split_s[s_size] = 0;
	return (split_s);
}
