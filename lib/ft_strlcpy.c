/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:14:58 by hkim2             #+#    #+#             */
/*   Updated: 2021/05/29 18:15:48 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (*(src + i))
		i++;
	if (dest == 0 && src == 0)
		return (i);
	while (*src && len + 1 < n)
	{
		*dest++ = *src++;
		len++;
	}
	if (n > 0)
		*dest = 0;
	return (i);
}
