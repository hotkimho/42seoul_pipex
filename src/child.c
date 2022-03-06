/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:41:33 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/06 18:20:35 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_process(t_pipeinfo *pipeinfo, int pid)
{
	close(pipeinfo->fd[1]);
	dup2(pipeinfo->fd[0], STDIN_FILENO);
	close(pipeinfo->fd[0]);
	waitpid(pid, NULL, WNOHANG);
}

void	read_child_process(t_pipeinfo *pipeinfo, char **argv, char **env)
{	
	char	*cmd;
	char	**cmd_arg;

	cmd_arg = split_argv(argv, 2);
	cmd = get_cmd(pipeinfo->cmd_path, cmd_arg[0]);
	close(pipeinfo->fd[0]);
	dup2(pipeinfo->fd[1], STDOUT_FILENO);
	close(pipeinfo->fd[1]);
	dup2(pipeinfo->r_fd, STDIN_FILENO);
	close(pipeinfo->r_fd);
	if (execve(cmd, cmd_arg, env) == -1)
		perror_msg("command not found: ", 127);
}

void	write_process(t_pipeinfo *pipeinfo, char **argv, char **env, int idx)
{
	char	*cmd;
	char	**cmd_arg;

	cmd_arg = split_argv(argv, idx);
	cmd = get_cmd(pipeinfo->cmd_path, cmd_arg[0]);
	close(pipeinfo->fd[1]);
	close(pipeinfo->fd[0]);
	dup2(pipeinfo->w_fd, STDOUT_FILENO);
	close(pipeinfo->w_fd);
	if (execve(cmd, cmd_arg, env) == -1)
		perror_msg("command not found: ", 127);
}
