/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:33:47 by damarry           #+#    #+#             */
/*   Updated: 2022/03/10 19:45:14 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

// pipex_check.c
void	error_cmd(char *cmd);
void	error_file(char *file);
void	error_process(void);
void	check_args(int argc);
void	free_arr(char **arr);
void	check_fd(int *fd1, int *fd2, char **argv);
// pipex_utils.c
int		freer(char **arr, char *cmd);
char	*cmd_checker(char **env, char *cmd);
char	*path_parse(char **env, char *cmd);

#endif

// ./pipex file1 yes "head -10" file2
// ./pipex /dev/urandom "cat -e" "head -10" file2
