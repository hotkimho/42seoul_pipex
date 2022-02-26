/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:42:06 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/26 17:56:45 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	create_pipe(t_pipeinfo *pipeinfo)
{
	if (pipe(pipeinfo->fd) == -1)
		perror_msg("CREATE PIPE ERROR");
}

void	loop_fork(t_pipeinfo *pipeinfo, int argc, char **argv, char **env)
{
	int		pid;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		pid = fork();
		if (pid == -1)
			perror_msg("FORK ERROR");
		if (pid == 0 && i == 2)
			read_child_process(pipeinfo, argv, env);
		else if (pid == 0 && i == (argc - 2))
			write_child_process(pipeinfo, argv, env, i);
		else if (pid == 0)
			processing_child(pipeinfo, argv, env, i);
		else if (pid)
		{
			waitpid(pid, NULL, WNOHANG);
			i++;
		}
	}
}

void	pipex(t_pipeinfo *pipeinfo, int argc, char **argv, char **env)
{
	validation(argc);
	get_cmd_path(pipeinfo, env);
	read_input_file(pipeinfo, argv[1]);
	read_output_file(pipeinfo, argv[argc - 1]);
	create_pipe(pipeinfo);
	loop_fork(pipeinfo, argc, argv, env);
}