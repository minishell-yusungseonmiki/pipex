/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:12 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 16:08:33 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	pipe_open(int fd[2])
{
	if (pipe(fd) < 0)
		error("pipe error");
}

pid_t	make_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error("fork error");
	return (pid);
}

void	close_pipe(int fd[2])
{
	close(fd[READ]);
	close(fd[WRITE]);
}
