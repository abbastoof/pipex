/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:24 by atoof             #+#    #+#             */
/*   Updated: 2023/03/22 12:52:26 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_pipex *pipex, char *infile_path, char *outfile_path)
{
	int	value;

	value = TRUE;
	pipex->infile = open(infile_path, O_RDONLY);
	if (pipex->infile < 0)
	{
		perror("pipex");
		value = FALSE;
	}
	pipex->outfile = open(outfile_path, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		error("pipex");
	return (value);
}

void	fork_child1(t_pipex *pipex, char **argv, char **environ)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error("pipex");
	if (pipex->pid1 == 0)
		child1(*pipex, argv, environ);
	free_child(pipex);
}

void	fork_child2(t_pipex *pipex, char **argv, char **environ)
{
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error("pipex");
	if (pipex->pid2 == 0)
		child2(*pipex, argv, environ);
}

int	is_absolute_path(char *path)
{
	if (access(path, F_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	initialize_pipe(t_pipex *pipex)
{
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	pipex->end[0] = 0;
	pipex->end[1] = 0;
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_arguments = NULL;
	pipex->cmd = NULL;
}
