/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:36:15 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/23 17:58:25 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

void	error_msg(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	perror_msg(char *message)
{
	perror(message);
	exit(1);
}