/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:29:52 by seonmiki          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:07 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../../libft/libft.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*check_cmd_path(char **path, char *cmd)
{
	int		j;
	char	*cmd_path;
	char	*tmp;

	if (!access(cmd, X_OK))
	{
		free_path(path);
		return (cmd);
	}
	j = 0;
	while (path[j])
	{
		tmp = ft_strjoin(path[j], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(cmd_path, X_OK))
		{
			free_path(path);
			return (cmd_path);
		}
		free(cmd_path);
		j++;
	}
	free_path(path);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				error("malloc failed");
			break ;
		}
		i++;
	}
	return (check_cmd_path(path, cmd));
}

void	execute(char *cmd, char **envp)
{
	char	**cmd_parse;
	char	*cmd_path;

	cmd_parse = ft_split(cmd, ' ');
	if (!cmd_parse)
		error("malloc failed");
	cmd_path = find_path(cmd_parse[0], envp);
	if (!cmd_path)
		error("cmd not exist");
	execve(cmd_path, cmd_parse, envp);
}
