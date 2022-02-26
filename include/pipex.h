/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:27:16 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/26 17:58:06 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft.h"

typedef struct s_pipeinfo
{
	int		fd[2];
	int		r_fd;
	int		w_fd;
	char	**cmd_path;
	char	**cmds;
}			t_pipeinfo;

//pipe.c
void	create_pipe(t_pipeinfo *pipeinfo);
void	pipex(t_pipeinfo *pipeinfo, int argc, char **argv, char **env);
void	loop_fork(t_pipeinfo *pipeinfo, int argc, char **argv, char **env);

//parser.c
void	get_cmd_path(t_pipeinfo *pipeinfo, char **env);
int	find_cmd_index(char **cmd_path, char *cmd);
char	*get_cmd(char **cmd_path, char *cmd);
char	**split_argv(char **argv, int idx);

//child.c
void	read_child_process(t_pipeinfo *pipeinfo, char **argv, char **env);
void	write_child_process(t_pipeinfo *pipeinfo, char **argv, char **env, int idx);
void	processing_child(t_pipeinfo *pipeinfo, char **argv, char **env, int idx);

//read_file.c
void	read_input_file(t_pipeinfo *pipeinfo, char *path);
void	read_output_file(t_pipeinfo *pipeinfo, char *path);

//error.c
void	error_msg(char *message);
void	perror_msg(char *message);
void	close_all_fd(t_pipeinfo *pipeinfo);
void	validation(int argc);
#endif
