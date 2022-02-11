/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:51:07 by hkim2             #+#    #+#             */
/*   Updated: 2021/05/28 16:23:55 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		start;
	unsigned int		end;
	char				*ptr;

	if (!s1 || !set)
		return (NULL);
	start = -1;
	end = ft_strlen(s1) + 1;
	while (s1[++start])
		if (!ft_strchr(set, s1[start]))
			break ;
	while (--end > start)
		if (!ft_strchr(set, s1[end - 1]))
			break ;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}
