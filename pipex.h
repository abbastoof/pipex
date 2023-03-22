/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:25:44 by atoof             #+#    #+#             */
/*   Updated: 2023/03/10 15:44:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

# define FD_WRITE_END 1
# define FD_READ_END 0
# define TRUE 1
# define FALSE 0

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_arguments;
	char	*cmd;
}			t_pipex;
extern char	**environ;

void		error(char *error);
void		parent_free(t_pipex *pipex);
void		child1(t_pipex pipex, char **argv, char **envp);
void		child2(t_pipex pipex, char **argv, char **envp);
void		free_child(t_pipex *pipex);
char		*get_cmd(char **paths, char *cmd);
void		validate_args(int argc);
void		create_pipe(t_pipex *pipex);
void		get_command_paths(t_pipex *pipex);
void		get_command_arguments(t_pipex *pipex, char **argv);
void		wait_for_child_processes(t_pipex pipex);
char		*find_path(char **envp);
int			open_files(t_pipex *pipex, char *infile_path, char *outfile_path);
void		fork_child1(t_pipex *pipex, char **argv, char **environ);
void		fork_child2(t_pipex *pipex, char **argv, char **environ);
int			is_absolute_path(char *path);
void		initialize_pipe(t_pipex *pipex);

#endif
