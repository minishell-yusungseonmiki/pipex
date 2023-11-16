/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:18 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 16:11:55 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 1
#  error BUFFER_SIZE is too small
# endif

# define READ 0
# define WRITE 1
# define INFILE 0
# define OUTFILE 1

typedef struct s_pipex
{
	int		fd[2];
	int		file[2];
	int		child_cnt;
}	t_pipex;

void	free_path(char **path);
char	*check_cmd_path(char **path, char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);

void	wait_process(int child_cnt);
void	child_process(t_pipex pipe, int argc, char *argv, char **envp);
void	parent_process(t_pipex pipe);

void	error(char *msg);
void	inout_file_open(int file[2], int argc, char **argv);

void	pipe_open(int fd[2]);
pid_t	make_fork(void);
void	close_pipe(int fd[2]);

void	heredoc(t_pipex pipe, char **argv, char **envp);
void	cmd_append(t_pipex pipe, char **argv, char **envp);
void	cmd_heredoc(t_pipex pipe, char **argv, char **envp);

char	*get_next_line(int fd);

#endif