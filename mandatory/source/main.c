/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:04 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 15:15:43 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../../libft/libft.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	child_process(int fd[2], char **argv, char **envp)
{
	int	fd_f1;

	close(fd[0]);
	fd_f1 = open(argv[1], O_RDONLY);
	if (fd_f1 < 0)
		error("open failed");
	dup2(fd_f1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute(argv[2], envp);
	error("execute failed");
}

void	parent_process(int fd[2], char **argv, char **envp)
{
	int	fd_f2;

	close(fd[1]);
	fd_f2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd_f2 < 0)
		error("open failed");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_f2, STDOUT_FILENO);
	execute(argv[3], envp);
	error("execute failed");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error("pipe error");
		pid[0] = fork();
		if (pid[0] < 0)
			error("fork error");
		else if (pid[0] == 0)
			child_process(fd, argv, envp);
		pid[1] = fork();
		if (pid[1] < 0)
			error("fork error");
		else if (pid[1] == 0)
			parent_process(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		error("argc not correct");
	return (0);
}
