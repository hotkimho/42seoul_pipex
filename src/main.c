/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:06 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/24 18:52:31 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>

void	get_cmd_path(t_pipeinfo *pipeinfo, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (env[i] == NULL)
		error_msg("CMD PARSE ERROR");
	pipeinfo->cmd_path = ft_split(env[i] + 5, ':');
}

int	find_cmd_index(char **cmd_path, char *cmd)
{
	int	i;
	char	*str;

	i = 0;
	while (cmd_path[i])
	{
		str = ft_strjoin(cmd_path[i], cmd);
		if (access(str, F_OK) == 0)
			return (i);
		free(str);
		i++;
	}
	return (-1);
}

void	validation(int argc)
{
	if (argc == 10)
		error_msg("Invalid arg");
}

void	read_input_file(t_pipeinfo *pipeinfo, char *path)
{
	if (access(path, F_OK) == 0)
	{
		pipeinfo->r_fd = open(path, O_RDONLY);
		if (pipeinfo->r_fd == -1)
			perror_msg("READ_INPUT_FILE OPEN ERROR ");
	}
	else
		perror_msg("READ_INPUT_FILE ERROR ");
}

void	create_pipe(t_pipeinfo *pipeinfo)
{
	if (pipe(pipeinfo->fd) == -1)
		perror_msg("CREATE PIPE ERROR");
}

char	*get_cmd(char **cmd_path, char *cmd)
{
	int		cmd_idx;
	char	*add_slash_cmd;
	char	*path_cmd;

	add_slash_cmd = ft_strjoin("/", cmd);
	cmd_idx = find_cmd_index(cmd_path, add_slash_cmd);
	path_cmd = ft_strjoin(cmd_path[cmd_idx], add_slash_cmd);
	if (add_slash_cmd)
		free(add_slash_cmd);
	return (path_cmd);
}

void	pipex(t_pipeinfo *pipeinfo, int argc, char **argv, char **env)
{
	int	pid;

	validation(argc);
	get_cmd_path(pipeinfo, env);
	read_input_file(pipeinfo, argv[1]);
	create_pipe(pipeinfo);
	
	pid = fork();
	if (pid == -1)
		perror_msg("FORK ERROR");
	//pipex infile cat
	//execve(path + cat, [cat, ...], end);
	//부모 프로세스
	if (pid != 0)
	{
		close(pipeinfo->fd[1]);

	}
	//자식 프로세스
	else
	{
		close(pipeinfo->fd[0]);
		
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipeinfo	pipe_info;

	pipex(&pipe_info, argc, argv, env);
	exit(0);
}