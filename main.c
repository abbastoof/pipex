/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:47:40 by atoof             #+#    #+#             */
/*   Updated: 2023/03/10 15:50:13 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	close_pipes(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
}

int	main(int argc, char **argv)
{
	t_pipex	pipex;

	initialize_pipe(&pipex);
	validate_args(argc);
	create_pipe(&pipex);
	get_command_paths(&pipex);
	get_command_arguments(&pipex, argv);
	if (open_files(&pipex, argv[1], argv[4]) == TRUE)
		fork_child1(&pipex, argv, environ);
	get_command_arguments(&pipex, argv + 1);
	fork_child2(&pipex, argv, environ);
	close_pipes(&pipex);
	free_child(&pipex);
	wait_for_child_processes(pipex);
	parent_free(&pipex);
	return (0);
}
