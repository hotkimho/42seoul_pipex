/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:22:07 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/06 18:03:13 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	error_msg(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	perror_msg(char *message, int code)
{
	perror(message);
	exit(code);
}

void	close_all_fd(t_pipeinfo *pipeinfo)
{
	if (pipeinfo->fd[0])
		close(pipeinfo->fd[0]);
	if (pipeinfo->fd[1])
		close(pipeinfo->fd[1]);
	if (pipeinfo->r_fd)
		close(pipeinfo->r_fd);
	if (pipeinfo->w_fd)
		close(pipeinfo->w_fd);
}

void	validation(int argc)
{
	if (argc < 5)
		error_msg("Invalid arg");
}
