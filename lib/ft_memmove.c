/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:38:41 by hkim2             #+#    #+#             */
/*   Updated: 2021/05/29 18:44:40 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst < src)
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	else
		while (len)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
	return (dst);
}
