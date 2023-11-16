/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:18 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/16 15:09:05 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

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

#endif