/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:33:56 by damarry           #+#    #+#             */
/*   Updated: 2022/03/10 16:33:57 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_file(char *file)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd("\033[31mError:\e[0m command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError:\e[0m Wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		exit(EXIT_SUCCESS);
	}
}

void	error_process(void)
{
	perror("\033[31mError:\e[0m ");
	exit(EXIT_FAILURE);
}

void	check_fd(int *fd1, int *fd2, char **argv)
{
	*fd1 = open(argv[1], O_RDONLY);
	if (*fd1 == -1)
		error_file(argv[1]);
	*fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*fd2 == -1)
		error_file(argv[4]);
}
