/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:36:34 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/26 17:36:43 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	read_input_file(t_pipeinfo *pipeinfo, char *path)
{
	if (access(path, F_OK) == 0)
	{
		pipeinfo->r_fd = open(path, O_RDONLY);
		if (pipeinfo->r_fd == -1)
			perror_msg("INPUT_FILE OPEN ERROR ");
	}
	else
		perror_msg("READ_INPUT_FILE ERROR ");
}

void	read_output_file(t_pipeinfo *pipeinfo, char *path)
{
	if (access(path, F_OK) == 0)
	{

		pipeinfo->w_fd = open(path, O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (pipeinfo->w_fd == -1)
			perror_msg("OUTPUT_FILE OPEN ERROR ");
	}
	else
		perror_msg("READ_OUTPT_FILE ERROR ");
}