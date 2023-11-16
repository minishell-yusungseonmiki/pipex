/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:08:12 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 15:14:41 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	wait_process(int child_cnt)
{
	int	i;

	i = 0;
	while (i < child_cnt)
	{
		if (wait(NULL) < 0)
			error("wait error");
		i++;
	}
}

void	child_process(t_pipex pipe, int argc, char *argv, char **envp)
{
	dup2(pipe.file[INFILE], STDIN_FILENO);
	if (pipe.child_cnt == argc - 4)
		dup2(pipe.file[OUTFILE], STDOUT_FILENO);
	else
		dup2(pipe.fd[WRITE], STDOUT_FILENO);
	execute(argv, envp);
	error("execute failed");
}

void	parent_process(t_pipex pipe)
{
	dup2(pipe.fd[READ], pipe.file[INFILE]);
	close(pipe.fd[WRITE]);
}
