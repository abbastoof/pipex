/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:17:36 by atoof             #+#    #+#             */
/*   Updated: 2023/03/10 15:38:32 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*get_cmd is a static function that takes in an array
of paths and a command, and returns a pointer to a string
,temp is a pointer to a string that will be used to
temporarily store a concatenation of a path and a "/"
,unix_cmd is a pointer to a string that will be used to
temporarily store a concatenation of a path, a "/", and a command
if no valid command is find, return null*/

char	*get_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*unix_cmd;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		unix_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(unix_cmd, 0) == 0)
			return (unix_cmd);
		free(unix_cmd);
		paths++;
	}
	return (NULL);
}

void	child1(t_pipex pipex, char *argv[], char *envp[])
{
	if (dup2(pipex.end[FD_WRITE_END], STDOUT_FILENO) < 0)
		exit(1);
	close(pipex.end[FD_READ_END]);
	if (dup2(pipex.infile, STDIN_FILENO) < 0)
		error("pipex");
	if (!pipex.cmd)
	{
		free_child(&pipex);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_arguments, envp) == -1)
		error("pipex");
}

void	child2(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.end[FD_READ_END], STDIN_FILENO) < 0)
		exit(1);
	close(pipex.end[FD_WRITE_END]);
	if (dup2(pipex.outfile, STDOUT_FILENO) < 0)
		error("pipex");
	if (!pipex.cmd)
	{
		free_child(&pipex);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_arguments, envp) == -1)
		error("pipex");
}
