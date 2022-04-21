/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:34:01 by damarry           #+#    #+#             */
/*   Updated: 2022/03/10 19:27:50 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*cmd_checker(char **env, char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (cmd);
	else
		return (path_parse(env, cmd));
}

int	freer(char **arr, char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		free(cmd);
		cmd = NULL;
	}
	while (arr[i])
	{
		free(arr[i]);
		i += 1;
	}
	free(arr);
	arr = NULL;
	return (1);
}

char	*path_parse(char **env, char *cmd)
{
	int		i;
	char	**pathes;
	char	*full_cmd;

	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i ++;
	env[i] = ft_strtrim(env[i], "PATH=");
	pathes = ft_split(env[i], ':');
	free(env[i]);
	i = 0;
	while (pathes[i])
	{
		full_cmd = ft_strjoin(pathes[i], cmd);
		if (access(full_cmd, F_OK) == 0 && freer(pathes, cmd))
			return (full_cmd);
		i += 1;
		free(full_cmd);
		full_cmd = NULL;
	}
	freer(pathes, cmd);
	error_cmd(cmd);
	return (NULL);
}
