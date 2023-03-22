/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:46 by atoof             #+#    #+#             */
/*   Updated: 2023/03/10 15:44:29 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("pipex: Argument numbers is invalid\n", STDERR_FILENO);
		exit(1);
	}
}

void	create_pipe(t_pipex *pipex)
{
	if (pipe(pipex->end) < 0)
		perror("pipex");
}

void	get_command_paths(t_pipex *pipex)
{
	pipex->paths = find_path(environ);
	pipex->cmd_paths = ft_split(pipex->paths, ':');
}

void	get_command_arguments(t_pipex *pipex, char **argv)
{
	pipex->cmd_arguments = ft_split(argv[2], ' ');
	if (is_absolute_path(pipex->cmd_arguments[0]))
		pipex->cmd = ft_strdup(pipex->cmd_arguments[0]);
	else
		pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_arguments[0]);
}

void	wait_for_child_processes(t_pipex pipex)
{
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
