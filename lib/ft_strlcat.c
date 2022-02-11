/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:40:31 by hkim2             #+#    #+#             */
/*   Updated: 2021/05/29 17:01:54 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		index;
	size_t		dest_len;
	size_t		src_len;

	index = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (size + src_len);
	while (*src && dest_len + index + 1 < size)
		*(dest + dest_len + index++) = *(src++);
	*(dest + dest_len + index) = 0;
	return (dest_len + src_len);
}
