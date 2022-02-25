/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:34:09 by hkim2             #+#    #+#             */
/*   Updated: 2022/02/25 17:11:09 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EXIT_FAILURE 1
# include <stdio.h>
# include "../lib/libft.h"

void	error_msg(char *message);
void	perror_msg(char *message);

#endif