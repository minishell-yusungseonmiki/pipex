/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:04 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 16:14:23 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	inout_file_open(int file[2], int argc, char **argv)
{
	file[INFILE] = open(argv[1], O_RDONLY);
	if (file[INFILE] < 0)
		error("file open failed");
	file[OUTFILE] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (file[OUTFILE] < 0)
		error("file open failed");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipe;
	pid_t	pid;

	pipe.child_cnt = 0;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		heredoc(pipe, argv, envp);
	else if (argc >= 5)
	{
		inout_file_open(pipe.file, argc, argv);
		while (pipe.child_cnt < argc - 3)
		{
			pipe_open(pipe.fd);
			pid = make_fork();
			if (pid == 0)
				child_process(pipe, argc, argv[pipe.child_cnt + 2], envp);
			else
				parent_process(pipe);
			pipe.child_cnt++;
		}
		close_pipe(pipe.fd);
		wait_process(pipe.child_cnt);
	}
	else
		error("argc not enough");
	return (0);
}
