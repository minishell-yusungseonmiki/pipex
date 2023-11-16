/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:43:27 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 17:30:57 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	cmd_heredoc(t_pipex pipe, char **argv, char **envp)
{
	char	*tmp;

	close(pipe.fd[READ]);
	pipe.file[INFILE] = open("infile", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pipe.file[INFILE] < 0)
		error("file error");
	tmp = get_next_line(0);
	while (tmp)
	{
		if (!ft_strncmp(argv[2], tmp, ft_strlen(argv[2])))
			break ;
		write(pipe.file[INFILE], tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(0);
	}
	close(pipe.file[INFILE]);
	pipe.file[INFILE] = open("infile", O_RDWR | O_CREAT, 0666);
	dup2(pipe.file[INFILE], STDIN_FILENO);
	dup2(pipe.fd[WRITE], STDOUT_FILENO);
	execute(argv[3], envp);
	error("execute failed");
}

void	cmd_append(t_pipex pipe, char **argv, char **envp)
{
	close(pipe.fd[WRITE]);
	pipe.file[OUTFILE] = open(argv[5], O_RDWR | O_CREAT | O_APPEND, 0666);
	if (pipe.file[OUTFILE] < 0)
		error("file error");
	dup2(pipe.fd[READ], STDIN_FILENO);
	dup2(pipe.file[OUTFILE], STDOUT_FILENO);
	execute(argv[4], envp);
	error("execute failed");
}

void	heredoc(t_pipex pipe, char **argv, char **envp)
{
	pid_t	pid;

	pipe_open(pipe.fd);
	pid = make_fork();
	if (pid == 0)
		cmd_heredoc(pipe, argv, envp);
	pid = make_fork();
	if (pid == 0)
		cmd_append(pipe, argv, envp);
	close(pipe.fd[READ]);
	close(pipe.fd[WRITE]);
	wait(NULL);
	wait(NULL);
}
