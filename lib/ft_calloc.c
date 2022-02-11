/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:58:40 by hkim2             #+#    #+#             */
/*   Updated: 2021/05/29 18:30:54 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*ptr;
	unsigned char	*tmp;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (ptr);
}
