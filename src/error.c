/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:36:15 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/11 18:38:20 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_msg(char *message)
{
	ft_putstr_fd("error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}