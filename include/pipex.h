/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:27:16 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/25 16:32:46 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "./error.h"
# include "get_next_line.h"

typedef struct s_pipeinfo
{
	int		fd[2];
	int		r_fd;
	int		w_fd;
	char	**cmd_path;
	char	**cmds;
}			t_pipeinfo;

#endif
