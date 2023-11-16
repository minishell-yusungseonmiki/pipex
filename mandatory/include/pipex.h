/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:06:18 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/08 22:26:35 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void	free_path(char **path);
char	*check_cmd_path(char **path, char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);

void	error(char *msg);
void	child_process(int fd[2], char **argv, char **envp);
void	parent_process(int fd[2], char **argv, char **envp);

#endif