/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:06 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/11 20:26:25 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>



void	check_arg(int argc, char **argv)
{
	argc = 0;
	argv = NULL;
}

/*
정리할 함수
access
unlink
waitpid
wait
pipe
dup
dup2
execve
fork
perror
strerror
*/

int	main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	char **new_arg = (char **) malloc(sizeof(char *) * 5);
	new_arg[0] = "ls";
	new_arg[1] = argv[1];
	new_arg[2] = argv[2];
	new_arg[3] = argv[3];
	new_arg[4] = NULL;
	
	//printf("시작\n");
	execve("/bin/ls", new_arg, NULL);
	return (0);
}