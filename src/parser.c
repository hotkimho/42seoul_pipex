/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:32:12 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/05 17:47:15 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	int		i;
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
