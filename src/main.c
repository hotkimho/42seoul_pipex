/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:06 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/25 20:21:57 by hkim2            ###   ########.fr       */
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

char	**split_argv(char **argv, int idx)
{
	char	**str;

	str = ft_split(argv[idx], ' ');
	return (str);
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

void	child_process(t_pipeinfo *pipeinfo, char **argv, char **env, int idx)
{	
	char	*cmd;
	char	**cmd_arg;

	cmd_arg = split_argv(argv, idx);
	cmd = get_cmd(pipeinfo->cmd_path, cmd_arg[0]);
	close(pipeinfo->fd[0]);
	dup2(pipeinfo->fd[1], STDOUT_FILENO);
	close(pipeinfo->fd[1]);
	dup2(pipeinfo->r_fd, STDIN_FILENO);
	
	if (execve(cmd, cmd_arg, env) == -1)
	{
		close_all_fd(pipeinfo);
		perror_msg("EXECVE ERROR ");
	}
}

void	parent_process(t_pipeinfo *pipeinfo, char **argv, char **env)
{
	char	*cmd;
	char	**cmd_arg;

	cmd_arg = split_argv(argv, 3);
	cmd = get_cmd(pipeinfo->cmd_path, cmd_arg[0]);
	dup2(pipeinfo->fd[0], STDIN_FILENO);
	close(pipeinfo->fd[1]);
	dup2(pipeinfo->w_fd, STDOUT_FILENO);


	
	if (execve(cmd, cmd_arg, env) == -1)
	{
		close_all_fd(pipeinfo);
		perror_msg("EXECVE ERROR ");
	}
}

void	pipex(t_pipeinfo *pipeinfo, int argc, char **argv, char **env)
{
	int	pid;

	validation(argc);
	get_cmd_path(pipeinfo, env);
	read_input_file(pipeinfo, argv[1]);
	read_output_file(pipeinfo, argv[argc-1]);
	create_pipe(pipeinfo);

	pid = fork();
	if (pid == -1)
		perror_msg("FORK ERROR");
	//pipex infile "ls -l" "ls -l" out
	//execve(path + cat, [cat, ...], end);
	//부모 프로세스
	if (pid != 0)
	{
		printf("부모 시작\n");
		
		//wait(NULL);
		parent_process(pipeinfo, argv, env);
		printf("부모 끝\n");
	}
	//자식 프로세스
	else
	{
		printf("자식 시작\n");
		child_process(pipeinfo, argv, env, 2);
		printf("자식 끝\n");
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipeinfo	pipe_info;
	
	pipex(&pipe_info, argc, argv, env);
	exit(0);
}