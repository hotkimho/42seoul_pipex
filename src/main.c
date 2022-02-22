/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:06 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/22 18:57:49 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>


char	**get_cmd_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (env[i] == NULL)
		error_msg("CMD PARSE ERROR");
	return (ft_split(env[i] + 5, ':'));
}

int		check_file(char **cmd_path, char *cmd)
{
	int	i;
	char	*str;
	
	i = 0;
	while (cmd_path[i])
	{
		str = ft_strjoin(cmd_path[i], cmd);
		printf("%s\n", str);
		if (access(str, F_OK) == 0)
		{
			printf("find it\n");
			return 0;
		}
		free(str);
		i++;
	}
	return -1;
}

void	pipex(char **argv, char **env)
{
	char	**cmd_path;

	argv=NULL;
	cmd_path = get_cmd_path(env);
	check_file(cmd_path, "/ls");
}

void	validation(int argc)
{
	
}

int	main(int argc, char **argv, char **env)
{
	pipex(argv, env);
	//if (argc != 5)
	//	error_msg("Invalid arg");
	argc=1;
	for (int i = 0; i< argc; i++)
		printf("%s\n", argv[i]);
}